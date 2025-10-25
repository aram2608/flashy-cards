#!/bin/bash

git ls-files "*.cpp" | xargs clang-format -i