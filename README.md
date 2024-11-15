# TutorialZero
  这是一个使用 C++ 和 EasyX 图形库开发的简单游戏项目。玩家可以控制角色移动并射击敌人，游戏中包含得分系统和背景音乐。
## Directory Structure


. ├── img/          
游戏图像资源
├── mus/                   
游戏音频资源 
├── src/                    
源代码文件
│  ├── main.cpp 

│  ├── Globals.cpp

│  ├── Animation.cpp

│  ├── Player.cpp

│  ├── Enemy.cpp
│  ├── Bullet.cpp
│  ├── Button.cpp 
│  ├── StartGameButton.cpp 
│  ├── QuitGameButton.cpp
│  └── Utils.cpp 
├── include/           
# 头文件 
│  ├── Globals.h 
│  ├── Animation.h 
│  ├── Player.h 
│  ├── Enemy.h 
│  ├── Bullet.h 
│  ├── Button.h 
│  ├── StartGameButton.h 
│  ├── QuitGameButton.h 
│  └── Utils.h
├── Game.sln           
# Visual Studio 解决方案文件 
├── Game.vcxproj       
# Visual Studio 项目文件
└── README.md          
# 项目介绍
## 依赖项

- Visual Studio 2019 或更高版本
- EasyX 图形库

## 安装和运行

1. 克隆项目到本地：git clone https://github.com/tuzibuqiahuluobo/TutorialZero.git

2. 打开 Visual Studio，使用 `File -> Open -> Project/Solution` 打开 `Game.sln` 解决方案文件。

3. 确保已安装 EasyX 图形库，并在项目属性中正确配置库和包含目录。

4. 生成解决方案并运行项目。

## 游戏玩法

- 使用键盘方向键控制角色移动。
- 游戏开始后，敌人会不断生成，玩家需要躲避敌人并让小球在旋转的途中攻击敌人。
- 每击中一个敌人得一分，在玩家触碰到敌人时，游戏结束将会，并且显示最终得分。

## 贡献

欢迎提交问题和拉取请求来改进这个项目。请确保在提交前阅读并遵循项目的贡献指南。

## 许可证

该项目使用 MIT 许可证。详情请参阅 [LICENSE](LICENSE) 文件。
