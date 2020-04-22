cmake_minimum_required(VERSION 2.8.9)
project(Leaf)

file(GLOB SOURCES 
	"src/*")

add_executable(leaf ${SOURCES})
