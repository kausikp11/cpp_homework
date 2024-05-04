# TODO: Add your libraries here
# You must have the following libraries:
# - stb_image_data_view
# - drawer
# - image
# - pixelate_image
add_library(stb_image_data_view STATIC stb_image_data_view.cpp)
target_link_libraries(stb_image_data_view PUBLIC cxx_setup stb::stb ftxui::screen)
add_library(image STATIC image.cpp)
target_link_libraries(image PUBLIC cxx_setup ftxui::screen stb_image_data_view)
add_library(pixelate_image STATIC pixelate_image.cpp)
target_link_libraries(pixelate_image PUBLIC cxx_setup stb_image_data_view image)
add_library(drawer STATIC drawer.cpp)
target_link_libraries(drawer PUBLIC image ftxui::screen pixelate_image)

if(BUILD_TESTING)
add_executable(image_test image_test.cpp)
target_link_libraries(image_test PRIVATE cxx_setup image ftxui::screen GTest::gtest_main)

add_executable(stb_image_data_view_test stb_image_data_view_test.cpp)
target_link_libraries(stb_image_data_view_test PRIVATE cxx_setup stb_image_data_view stb::stb ftxui::screen GTest::gtest_main)

add_executable(pixelate_image_test pixelate_image_test.cpp)
target_link_libraries(pixelate_image_test PRIVATE cxx_setup pixelate_image stb::stb ftxui::screen GTest::gtest_main)

add_executable(drawer_test drawer_test.cpp)
target_link_libraries(drawer_test PRIVATE cxx_setup drawer stb::stb ftxui::screen GTest::gtest_main)
  include(GoogleTest)
  # TODO: Add your tests executable with all your tests here
  # Name it pixelator_tests.
  # Also use gtest_discover_tests(pixelator_tests)
  # to register them with CTest
  gtest_discover_tests(image_test) 
    gtest_discover_tests(stb_image_data_view_test) 
    gtest_discover_tests(pixelate_image_test) 
    gtest_discover_tests(drawer_test)
endif()
