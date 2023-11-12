# add_library: ライブラリ作成を指示する関数
# 第一引数: ライブラリ名
# 第二引数: STATICなら静的ライブラリ，SHAREDなら動的リンクライブラリ
# 第三引数以降: ライブラリに含まれるファイル名
add_library(
    bmi_check
    STATIC
    bmi_check.cpp
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
    bmi_check
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# target_compile_options:
# このターゲットのコンパイル時にコンパイラに渡されるオプションを指定する
target_compile_options(bmi_check PUBLIC "$<$<CONFIG:RELEASE>:-o3>")
target_compile_options(bmi_check PUBLIC "$<$<CONFIG:DEBUG>:-o0 -g>")

# target_compile_features:
# コンパイラに渡される追加のコンパイラフラグを指定する．
target_compile_features(bmi_check PUBLIC cxx_std_11)

# target_compile_definitions:
# コンパイラによるマクロ定義を指定する．
target_compile_definitions(bmi_check PUBLIC "$<$<CONFIG:RELEASE>:NDEBUG>")
