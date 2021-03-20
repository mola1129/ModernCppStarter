#include <srtools/srtools.h>

using namespace srtools;

Greeter::Greeter(std::string _name) : name(std::move(_name)) {}

std::string Greeter::greet(LanguageCode lang) const {
  switch (lang) {
    default:
    case LanguageCode::EN:
      return name;
    case LanguageCode::DE:
      return name;
    case LanguageCode::ES:
      return name;
    case LanguageCode::FR:
      return name;
  }
}
