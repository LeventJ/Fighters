#"飞机大战"项目实验报告#


----------
##What to do?##
**1. 基本规则：**

- 完成sfml配置，显示sfml.works  
- 显示一架静止的飞机与于屏幕底部
- 上下左右方向键控制飞机移动
- 限制上下左右边界
- 空格键开炮，显示运动的炮弹
- 炮弹飞出边界的处理
- 碰撞处理（敌机与炮弹碰撞）
- 显示敌机爆炸的过程
- 爆炸声音
- 计分及显示
- 敌机炮弹处理
- 被敌机击中处理（炸毁，三条命）
- 过关控制
	
**2. 拓展动作**

- 敌机分为两种，Boss和Enemy
- Boss能发射炮弹但速度较慢
- Enemy不能发射炮弹但速度很快
- 敌机有多条命，被击中不会立刻爆炸


----------
##How to do it?##
**1. 使用的工具**

- C++的IDE CodeBlocks
- 引用的外部工具类SFML
- Staruml

**2. 主要代码的实现**
	
	#include <SFML/Audio.hpp>
	#include <SFML/Graphics.hpp>
	#include "Sky.h"
	#include "Texture.h"
	#include "Music.h"
	#include "Myplane.h"
	#include <string>
	#include <iostream>
	#include <sstream>
	#include <stdlib.h>
	int main(int argc, char* argv[])
	{
	    Texture::load();
	    Music::load();
	    Sky* sky = Sky::getInstance();
	    sf::RenderWindow* window = sky->getWindow();
	    Music::BACK_GROUND.play();
	    Myplane myplane;
	    sky->addmyplane(&myplane);
	    sf::Clock clock;
	    sf::Time time;
	    //clock.restart();
	        int n = 0;
	        std::stringstream ss;
	        std::string str;
	        ss<<n;
	        ss>>str;
	        sf::Font font;
	        if (!font.loadFromFile("font/STHeiti Light.ttc"))
	            return EXIT_FAILURE;
	        sf::Text text("SCORES :"+str, font, 10);
	
	
	
	    while (window->isOpen())
	    {
	        // Process events
	        sf::Event event;
	        while (window->pollEvent(event))
	        {
	            // Close window: exit
	            if (event.type == sf::Event::Closed)
	                window->close();
	            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
	                window->close();
	            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
	                myplane.move_left();
	            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
	                myplane.move_right();
	            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
	                myplane.move_up();
	            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
	                myplane.move_down();
	            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
	                myplane.fire();
	
	        }
	        sky->refresh(text);
	    }
	    return EXIT_SUCCESS;
	}

**3. UML图**

![uml图](http://d.pcs.baidu.com/thumbnail/bf43270c88791aa4553f8e2709efd9b9?fid=3458628869-250528-505037927870523&time=1434974400&rt=sh&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-ck3Smxkr%2F4qHp6plQ1cmhO6i%2BWI%3D&expires=2h&prisign=unkown&chkv=0&chkbd=0&chkpc=&size=c850_u580&quality=100)



----------
##How about it?##

**1. 代码部分**

- 完成了所有基础内容
- 完成了拓展部分

**2. 游戏截图**

![截图1](http://d.pcs.baidu.com/thumbnail/f43cd85180683d890ce580a11ec4ed32?fid=3458628869-250528-706413159337556&time=1434974400&rt=sh&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-4dkc1tWwX5lb8jJbDqJQMSl%2BO2I%3D&expires=2h&prisign=unkown&chkv=0&chkbd=0&chkpc=&size=c850_u580&quality=100)

![截图2](http://d.pcs.baidu.com/thumbnail/c065c0b1da5727e1da9c090357c067fe?fid=3458628869-250528-624256796495084&time=1434974400&rt=sh&sign=FDTAER-DCb740ccc5511e5e8fedcff06b081203-k626jk7STOFNghDaGvU4qDXAPF8%3D&expires=2h&prisign=unkown&chkv=0&chkbd=0&chkpc=&size=c850_u580&quality=100)

----------
##User evaluation##

> 这个游戏很有难度，我喜欢。
> 
> ————匿名评论

