# add_executable:
# 実行ファイルの作成を指示する
# 第一引数: 実行ファイル名
# 第二引数以降: 実行ファイルのコンパイルに含まれるソースファイル
add_executable(
    bmi_check_test.out
    bmi_check_test.cpp
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
    bmi_check_test.out
    PRIVATE
    bmi_check
)

# target_include_directories:
# ターゲット(add_executable，add_libraryの第一引数で指定されるライブラリまたは実行ファイルのこと)
# に紐付いたヘッダファイルが含まれるディレクトリを指定する．
# 第一引数: ターゲット(ライブラリ名または実行ファイル名)
# 第二引数: PUBLIC このターゲットおよびこのライブラリに依存するターゲットがコンパイルされるときに参照される
#          PRIVATE このターゲットをコンパイルするときのみに参照される
#          INTERFACE このターゲットのコンパイルでは利用しないが，
#                    このライブラリを利用するターゲットがコンパイルされるときに参照される
# 第三引数以降: ヘッダファイルが配置されるディレクトリパス
target_include_directories(
    bmi_check_test.out
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# target_compile_options:
# このターゲットのコンパイル時にコンパイラに渡されるオプションを指定する
target_compile_options(bmi_check_test.out PUBLIC "$<$<CONFIG:RELEASE>:-o3>")
target_compile_options(bmi_check_test.out PUBLIC "$<$<CONFIG:DEBUG>:-o0 -g>")

# target_compile_features:
# コンパイラに渡される追加のコンパイラフラグを指定する．
target_compile_features(bmi_check_test.out PUBLIC cxx_std_11)

# target_compile_definitions:
# コンパイラによるマクロ定義を指定する．
target_compile_definitions(bmi_check_test.out PUBLIC "$<$<CONFIG:RELEASE>:NDEBUG>")
