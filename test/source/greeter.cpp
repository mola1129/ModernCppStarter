#include <doctest/doctest.h>
#include <srtools/srtools.h>

#include <string>

TEST_CASE("SRTools") {
  using namespace srtools;

  Greeter greeter("Tests");

  CHECK(greeter.greet(LanguageCode::EN) == "Hello, Tests!");
  CHECK(greeter.greet(LanguageCode::DE) == "Hallo Tests!");
  CHECK(greeter.greet(LanguageCode::ES) == "¡Hola Tests!");
  CHECK(greeter.greet(LanguageCode::FR) == "Bonjour Tests!");
}

// TEST_CASE("Greeter version") {
//   static_assert(std::string_view(SRTOOLS_VERSION) == std::string_view("1.0"));
//   CHECK(std::string(SRTOOLS_VERSION) == std::string("1.0"));
// }
