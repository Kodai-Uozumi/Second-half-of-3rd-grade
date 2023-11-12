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
# プロジェクトの名前と使われる言語を指定．
project(bmi_check LANGUAGES CXX)

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
add_test(unittest ${PROJECT_BINARY_DIR}/tests/bmi_check_test.out)

# add_executable:
# 実行ファイルの作成を指示する
# 第一引数: 実行ファイル名
# 第二引数以降: 実行ファイルのコンパイルに含まれるソースファイル
add_executable(
    bmi_checker.out
    main.cpp
)

# target_link_libraries: 
# ターゲット(add_executable，add_libraryの第一引数で指定されるライブラリまたは実行ファイルのこと)
# にリンクするライブラリを指定する．
# 第一引数: ターゲット（実行ファイル名またはライブラリ名）
# 第二引数: PUBLIC このターゲットおよびこのライブラリに依存するターゲットがリンクするときに参照される
#          PRIVATE このターゲットがリンクするときのみに参照される
#          INTERFACE このライブラリのリンクでは参照しないが，
#                    このライブラリを利用するターゲットがリンクするときに参照される
# 第二引数以降: ターゲットがリンクするライブラリ名
target_link_libraries(
    bmi_checker.out
    PRIVATE
    bmi_check
)

# target_compile_options:
# このターゲットのコンパイル時にコンパイラに渡されるオプションを指定する
target_compile_options(bmi_checker.out PUBLIC "$<$<CONFIG:RELEASE>:-o3>")
target_compile_options(bmi_checker.out PUBLIC "$<$<CONFIG:DEBUG>:-o0 -g>")

# target_compile_features:
# コンパイラに渡される追加のコンパイラフラグを指定する．
target_compile_features(bmi_checker.out PUBLIC cxx_std_11)

# target_compile_definitions:
# コンパイラによるマクロ定義を指定する．
target_compile_definitions(bmi_checker.out PUBLIC "$<$<CONFIG:RELEASE>:NDEBUG>")


