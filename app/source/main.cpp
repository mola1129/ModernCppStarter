#include <srtools/srtools.h>

#include <iostream>
#include <string>
#include <unordered_map>

auto main(int argc, char** argv) -> int {
  const std::unordered_map<std::string, srtools::LanguageCode> languages{
      {"en", srtools::LanguageCode::EN},
      {"de", srtools::LanguageCode::DE},
      {"es", srtools::LanguageCode::ES},
      {"fr", srtools::LanguageCode::FR},
  };


  std::string language;
  std::string name;

  auto langIt = languages.find(language);
  if (langIt == languages.end()) {
    std::cerr << "unknown language code: " << language << std::endl;
    return 1;
  }

  srtools::Greeter srtools(name);
  std::cout << srtools.greet(langIt->second) << std::endl;

  return 0;
}
