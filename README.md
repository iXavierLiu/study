# study
日常练习

## 项目依赖
- [gtest](https://github.com/google/googletest) 单元测试库

## 构建项目
### 项目结构
本项目完全通过cmake组织的，你可以在[`demo/modular`](demo/modular)下看到本项目是如何通过cmake将所有模块组织在一起的。

所有子目录都会有一个子项目名，并且和他的路径关联，例如目录`practices/leetcode`会创建一个名为`study_practices_leetcode`的子项目，他在cmake中的名字是`study::practices::leetcode`，并且他所依赖的子项目也会以相同的规则命名。这依赖于[`cmake/general.cmake`](cmake/general.cmake)会自动的创建相关的命名变量——在你调用`_setup_project_env`cmake宏之后。
### 开发环境
- g++ / clang / msvc 编译器(C++)
- [Visual Studio Code](https://code.visualstudio.com) (IDE)
- [vcpkg](https://github.com/microsoft/vcpkg) 用于解决依赖

后两者不是强制的，但是我更倾向使用可以跨平台的解决方案，所以优先推荐使用。
### 开始
#### 项目克隆
一切美好的事物都是从克隆仓库开始的
```shell
git clone git@github.com:iXavierLiu/study.git
```

#### 配置项目
在使用cmake生成构建项目前，你需要配置cmake预设，通过将`CMakeUserPresets.json.example`拷贝一份，并且去掉`example`后缀名来获得一份示例，这个json文件的结构非常简单和清晰，默认会有一个名为`osx-local`的预设作为macos上。
```shell
cd study
cp CMakeUserPresets.json.example CMakeUserPresets.json
```

你需要修改该预设的toolchain路径，使它指向你vcpkg对应的位置。有关CMake Prests的更多细节可以[查看文档]( https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html#manual:cmake-presets(7) )。
```shell
# 配置tool chain path
vim CMakeUserPresets.json
```

#### 解决依赖
然后你需要根据[【依赖】](#依赖)章节中的需要，通过vcpkg解决项目依赖，例如解决gtest项目依赖：
```shell
cd PATH_TO_VCPKG_ROOT
./vcpkg install gtest
```

#### 生成构建项目
然后使用`osx-local`预设生成项目，其中`osx-local`是要使用预设的名称，如果添加了其他的预设项目，请使用对应的预设名。
```shell
cmake --preset=osx-local
```

#### 作出修改
可使用你喜欢的IDE继续完成编辑，例如使用VS Code打开项目
```shell
cd PATH_TO_PROJECT_ROOT
code .
```
推荐在VSCode中安装[`CMake Tools`](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)插件，可以使用IDE的UI快速地使用cmake配置项目。

#### 编译
在刚刚生成的`out/build/osx-local`构建目录中编译整个项目，该目录是在[CMakePresets.json](CMakePresets.json)中的`default`预设中指定的。
```shell
cmake --build out/build/osx-local
```


