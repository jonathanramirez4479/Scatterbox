#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <stdlib.h>
#include <string>

namespace fs = std::filesystem;

int main() {
  std::string root_folder_name = "ScatterBox";

  const char *home_path = getenv("HOME");

  if (!home_path) {
    std::cerr << "HOME environment variable not found\n";
    return EXIT_FAILURE;
  }

  // Check if root folder already exists
  {
    std::string path = home_path;
    path += '/' + root_folder_name;
    if (fs::exists(path))
      std::cout << "Path exists\n";
    else {
      // Create root folder
      if (fs::create_directory(path))
        std::cout << "ScatterBox created at path: " << path << '\n';
      else {
        std::cerr << "Failed to create folder.\n";
      }
    }
  }

  return EXIT_SUCCESS;
}
