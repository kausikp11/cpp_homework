# TODO: Add your libraries here
# You must have the following libraries:
# - stb_image_data_view
# - drawer
# - image
# - pixelate_image
add_library(stb_image_data_view STATIC stb_image_data_view.cpp)
target_link_libraries(stb_image_data_view PUBLIC cxx_setup stb::stb ftxui::screen)
add_library(image STATIC image.cpp)
target_link_libraries(image PUBLIC cxx_setup stb::stb ftxui::screen stb_image_data_view)

if(BUILD_TESTING)
  include(GoogleTest)
  # TODO: Add your tests executable with all your tests here
  # Name it pixelator_tests.
  # Also use gtest_discover_tests(pixelator_tests)
  # to register them with CTest
endif()
