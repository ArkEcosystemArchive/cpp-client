#!/usr/bin/env bash
# This file is part of Ark Cpp Client.
#
# (c) Ark Ecosystem <info@ark.io>
#
# For the full copyright and license information, please view the LICENSE
# file that was distributed with this source code.
 
# #########
# This script extends support to the Arduino IDE.
#
# The Arduino IDE doesn't support extending its search path outside of the 'src' folder.
# The Ark Cpp-Client SDK exposes its public interface via the 'include' folder.
#
# This script moves the headers from 'include' into their relative directories in the 'src' folder;
# it then delete the 'include' folder.
#
# Additionally, once this script has been ran, it can be executed again to undo these changes.
# (i.e. recreates the directory tree and moves headers back to 'include'.)
# #########

# Flags
# You can skip the interface by passing '--auto'; eg 'bash ARDUINO_IDE.sh -auto'
AUTO='0'
if [ "$1" == "--auto" ]; then
  AUTO='1'
fi

# Directories
EXTRAS_DIR=$(dirname $0)
PROJECT_ROOT=${EXTRAS_DIR}/../
INCLUDE_DIR=${EXTRAS_DIR}/../src/include
INCLUDE_CLIENT_DIR=${INCLUDE_DIR}/cpp-client
SRC_DIR=${EXTRAS_DIR}/../src

INCLUDE_API_DIR=${INCLUDE_CLIENT_DIR}/api
SRC_API_DIR=${SRC_DIR}/api

INCLUDE_CONNECTION_DIR=${INCLUDE_CLIENT_DIR}/connection
SRC_CONNECTION_DIR=${SRC_DIR}/connection

INCLUDE_HTTP_DIR=${INCLUDE_CLIENT_DIR}/http
SRC_HTTP_DIR=${SRC_DIR}/http

if [[ $AUTO == '0' ]]; then

# Interface
echo -e "\n\n👋  Welcome Aboard  🚢\n\n"
sleep 1

if [[ -d ${INCLUDE_CLIENT_DIR} ]]; then
  echo -e "🤖  This script extends compatibility to the Arduino IDE  🤖\n"
  sleep 1
  echo -e "💪  All header files will be moved to their 'src' folders  💪\n"
  sleep 1
else
  echo -e "🤖  Looks like this library was already converted to support the Arduino IDE  🤖\n"
  sleep 1
  echo -e "💪  All header files will be moved back to the 'include' folder  💪\n"
  sleep 1
fi

echo -e "\n🛑  These changes are permanent, any unsaved changes will be lost  🛑\n"
sleep 2

# Prompts for continuation
read -p "⚠️  Are you sure you want to continue? (Y/n):" -n 1 -r
echo
if [[ ${REPLY} =~ ^[Nn]$ ]]; then
  echo -e "\n\n👌 Exiting script...\nNo Changes were made 👍\n\n";
  exit 0;
else
  echo -e "\n\n👌 Let's go!\n";
fi

fi  # /if [[ ${AUTO} ]]; then

if [[ -d ${INCLUDE_CLIENT_DIR} ]]; then
  # This will run if headers are in the 'include' directory tree.
  echo -e "****************************************\n"
  echo -e "Moving 'arkClient.h' to 'src' directory.\n"
  mv ${INCLUDE_CLIENT_DIR}/arkClient.h ${SRC_DIR}

  echo -e "Moving API headers.\n"
  mv ${INCLUDE_API_DIR}/api_base.hpp      ${SRC_API_DIR}
  mv ${INCLUDE_API_DIR}/api_handler.hpp   ${SRC_API_DIR}
  mv ${INCLUDE_API_DIR}/api.hpp           ${SRC_API_DIR}

  echo -e "Moving 'connection.hpp' to 'src/connection'.\n"
  mv ${INCLUDE_CONNECTION_DIR}/connection.hpp ${SRC_CONNECTION_DIR}

  echo -e "Moving 'http_support.hpp'\n"
  mv ${INCLUDE_HTTP_DIR}/http_support.hpp ${SRC_HTTP_DIR}

  echo -e "Moving Docs to the './extras' directory.\n"
  mv ${PROJECT_ROOT}/docs ${EXTRAS_DIR}

  echo -e "Removing old directories 🗑\n"
  rm -rf ${INCLUDE_DIR}

  echo -e "****************************************\n"
  echo -e "\nAll Done!\n👏👏👏👏👏\n"
  echo -e "\nYou can now use Cpp-Client with the Arduino IDE 👍\n\n"
  exit 0

else
  # This will run if headers are already in the 'src' directory tree.
  echo -e "****************************************\n"
  echo -e "Creating the 'include' folder 🗂\n"
  mkdir ${INCLUDE_DIR}
  mkdir ${INCLUDE_CLIENT_DIR}

  echo -e "Moving 'arkClient.h' back to the 'include' directory.\n"
  mv ${SRC_DIR}/arkClient.h ${INCLUDE_CLIENT_DIR}

  echo -e "Recreating API directory 🗂\n"
  mkdir ${INCLUDE_API_DIR}

  echo -e "Moving Api headers back to the 'include' tree.\n"
  mv ${SRC_API_DIR}/api_base.hpp      ${INCLUDE_API_DIR}
  mv ${SRC_API_DIR}/api_handler.hpp   ${INCLUDE_API_DIR}
  mv ${SRC_API_DIR}/api.hpp           ${INCLUDE_API_DIR}

  echo -e "Recreating the 'connection' folder 🗂"
  mkdir ${INCLUDE_CONNECTION_DIR}

  echo -e "Moving 'connection.hpp' to 'include/cpp-client/connection'.\n"
  mv ${SRC_CONNECTION_DIR}/connection.hpp ${INCLUDE_CONNECTION_DIR}

  echo -e "Recreating the 'http' folder 🗂"
  mkdir ${INCLUDE_HTTP_DIR}

  echo -e "Moving 'http_support.hpp'\n"
  mv ${SRC_HTTP_DIR}/http_support.hpp ${INCLUDE_HTTP_DIR}

  echo -e "Moving Docs back to the project root directory.\n"
  mv ${EXTRAS_DIR}/docs  ${PROJECT_ROOT}

  echo -e "****************************************\n"
  echo -e "\nAll Done!\n👏👏👏👏👏\n"
  echo -e "\nArduino IDE compatibility has been reverted 👍\n\n"
  exit 0

fi
