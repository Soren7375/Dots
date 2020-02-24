#include <SFML/Graphics.hpp>
#include "Find.h"
#include "II.h"
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(480, 560),"");
	Texture menu;
	menu.loadFromFile("image/m1.png");
	Sprite menu1(menu);
	Texture menu3;
	menu3.loadFromFile("image/m2.png");
	Sprite menu2(menu3);
	Texture gm;
	gm.loadFromFile("image/tiles.png");
	Sprite tile(gm);
	Texture on;
	on.loadFromFile("image/Numbers1.jpg");
	Sprite onum(on);
	Texture bn;
	bn.loadFromFile("image/Numbers2.jpg");
	Sprite bnum(bn);

	Texture o;
	o.loadFromFile("image/o.png");
	Sprite or(o);
	Texture b;
	b.loadFromFile("image/b.png");
	Sprite br(b);
	Texture w;
	w.loadFromFile("image/win.png");
	Sprite win(w);
	Texture st;
	st.loadFromFile("image/start.png");
	Sprite start(st);

	int ivmenu = 0;
	int oscore = 0;
	int bscore = 0;
	int iv = 1;
	int grid[30][30], grid2[30][30];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			grid[i][j] = 0;
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			grid2[i][j] = 0;
	while (window.isOpen())
	{
		Vector2i pos = Mouse::getPosition(window);
		int x = pos.x;
		int y = pos.y;
		Vector2i posmouse = Mouse::getPosition(window);
			int xg = posmouse.x / 16;
			int yg = posmouse.y / 16;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
			if (event.type == Event::MouseButtonPressed)
				if(event.key.code == Mouse::Left && ivmenu == 1)
				{
					if (iv == 1 && grid[xg][yg] == 0)
					{
						grid[xg][yg] = 1;
						iv = 2;
					}
					if (iv == 2 && grid[xg][yg] == 0)
					{
						grid[xg][yg] = 2;
						iv = 1;
					}
				}

			if (event.type == Event::MouseButtonPressed)
				if (event.key.code == Mouse::Left && ivmenu == 2)
				{
					if (iv == 1 && grid[xg][yg] == 0)
					{
						grid[xg][yg] = 1;
						grid2[xg][yg] = 1;
						iv = 2;
					}
					if (iv == 2)
					{
						int xy[2];
						find_cx(grid2, xy);
						grid[xy[1]][xy[0]] = 2;
						grid2[xy[1]][xy[0]] = 2;
						iv = 1;
					}
				}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::End)
			{
				ivmenu = 0;
				for (int i = 0; i < 30; i++)
					for (int j = 0; j < 30; j++)
						grid[i][j] = 0;
				oscore = 0;
				bscore = 0;
				iv = 1;
			}
		if (event.type == Event::MouseButtonPressed)
			if (event.key.code == Mouse::Right && ivmenu == 0)
			{
				if (x > menu1.getGlobalBounds().left && x < menu1.getGlobalBounds().left + menu1.getGlobalBounds().width && y>menu1.getGlobalBounds().top && y < menu1.getGlobalBounds().top + menu1.getGlobalBounds().height)
				{
					ivmenu = 1;
				}
				if (x > menu2.getGlobalBounds().left && x < menu2.getGlobalBounds().left + menu2.getGlobalBounds().width && y>menu2.getGlobalBounds().top && y < menu2.getGlobalBounds().top + menu2.getGlobalBounds().height)
					ivmenu = 2;
			}
		
		if (ivmenu == 0)
		{
			window.clear(Color::White);
			menu1.setPosition(173, 154);
			window.draw(menu1);
			menu2.setPosition(173, 210);
			window.draw(menu2);
		}
//---------------------------------Two Player-----------------------------------------------//
		if (ivmenu == 1)
		{
			window.clear(Color::White);
			for (int i = 0; i < 30; i++)
				for (int j = 0; j < 30; j++)
				{
					if (grid[i][j] == 0)
					{
						tile.setTextureRect(IntRect(0, 0, 16, 16));
						tile.setPosition(16 * i, 16 * j);
						window.draw(tile);
					}
					if (grid[i][j] == 1)
					{
						tile.setTextureRect(IntRect(16, 0, 16, 16));
						tile.setPosition(16 * i, 16 * j);
						window.draw(tile);
					}
					if (grid[i][j] == 2)
					{
						tile.setTextureRect(IntRect(32, 0, 16, 16));
						tile.setPosition(16 * i, 16 * j);
						window.draw(tile);
					}
				}
			oscore = find_o(grid);
			onum.setTextureRect(IntRect(40 * oscore, 0, 40, 72));
			onum.setPosition(40, 480);
			window.draw(onum);
			bscore = find_b(grid);
			bnum.setTextureRect(IntRect(40 * bscore, 0, 40, 72));
			bnum.setPosition(400, 480);
			window.draw(bnum);
				if (iv == 1)
				{
					or.setPosition(166, 500);
					window.draw(or);
				}
				if (iv == 2)
				{
					br.setPosition(166, 500);
					window.draw(br);
				}
			if (oscore == 5)
			{
				win.setPosition(214, 530);
				window.draw(win);
				window.draw(or);
			}
			if (bscore == 5)
			{
				win.setPosition(214, 530);
				window.draw(win);
				window.draw(br);
			}
		}
//--------------------------------------------------------------------------//
		if (ivmenu == 2)
		{
			window.clear(Color::White);
			for (int i = 0; i < 30; i++)
				for (int j = 0; j < 30; j++)
				{
					if (grid[i][j] == 0)
					{
						tile.setTextureRect(IntRect(0, 0, 16, 16));
						tile.setPosition(16 * i, 16 * j);
						window.draw(tile);
					}
					if (grid[i][j] == 1)
					{
						tile.setTextureRect(IntRect(16, 0, 16, 16));
						tile.setPosition(16 * i, 16 * j);
						window.draw(tile);
					}
					if (grid[i][j] == 2)
					{
						tile.setTextureRect(IntRect(32, 0, 16, 16));
						tile.setPosition(16 * i, 16 * j);
						window.draw(tile);
					}
				}

			oscore = find_o(grid);
			onum.setTextureRect(IntRect(40 * oscore, 0, 40, 72));
			onum.setPosition(40, 480);
			window.draw(onum);
			bscore = find_b(grid);
			bnum.setTextureRect(IntRect(40 * bscore, 0, 40, 72));
			bnum.setPosition(400, 480);
			window.draw(bnum);
			if (iv == 1)
			{
				or.setPosition(166, 500);
				window.draw(or);
			}
			if (iv == 2)
			{
				br.setPosition(166, 500);
				window.draw(br);
			}
			if (oscore == 5)
			{
				win.setPosition(214, 530);
				window.draw(win);
				window.draw(or);
			}
			if (bscore == 5)
			{
				win.setPosition(214, 530);
				window.draw(win);
				window.draw(br);
			}
		}
		window.display();
	}

	return 0;
}