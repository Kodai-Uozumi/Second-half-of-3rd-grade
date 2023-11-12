# -- cmakeの基本的な使い方 --
# インストール方法(ubuntu)
# $ sudo apt update
# $ sudo apt install cmake
#
# 環境の作成
# $ mkdir build
# $ cd build
# $ cmake ..
# 
# (以下，build/ ディレクトリ直下で実行する)
# ビルド
# $ make
# 
# クリア
# $ make clear
# 
# テスト実行 (buildディレクトリ内で)
# $ make test
# 

# cmake_minimum_required:
# cmakeのバージョンを指定する．実行には少なくともこのバージョン以上が必要．
cmake_minimum_required(VERSION 3.8)

# project:
# プロジェクトの名前と使われる言語を指定している．
project(blackjack LANGUAGES CXX)

# CMAKE_BUILD_TYPEが指定されていないときはDebugを指定してビルドしています．
# CMAKE_BUILD_TYPEを指定するには，cmakeの実行時に
# $ cmake .. -DCMAKE_BUILD_TYPE=Release
# 等と指定すれば良い．
# CMAKE_BUILD_TYPEにはRelease, Debug, RelWithDebInfo, MinSizeRelがあります．
# RelWithDebInfoはリリース版オプションでデバッグ情報を付加，
# MinSizeRelは実行ファイルが最小サイズとなるようなオプションです．
if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, set to default: Debug")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# add_subdirectory:
# 子ディレクトリをプロジェクトに含めます．
# これによって，配下のディレクトリにあるCMakeLists.txtを実行します．
add_subdirectory(src)
add_subdirectory(tests)

# enable_testing:
# cmakeのテスト機能をONにする
enable_testing()

# add_test:
# テスト実行での実行ファイルを指定
# 第一引数: テスト名
# 第二引数以降: テストで実行する実行ファイル
add_test(blackjack_test ${PROJECT_BINARY_DIR}/tests/judge_test.out)

