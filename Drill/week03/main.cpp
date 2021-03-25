#include "Graph.h"
#include "Simple_window.h"

int main()
try{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window win {tl, 1000, 800, "Canvas"};

	int x_size=800;
	int y_size=800;
	int x_grid=100;
	int y_grid=100;

	Lines grid;
	for(int x=x_grid; x<=x_size; x+=x_grid)
		grid.add(Point{x,0},Point{x,y_size}); //fuggoleges/vertical
	for(int y=y_grid; y<=y_size; y+=y_grid)
		grid.add(Point{0,y},Point{x_size,y}); //vizszintes/horizontal
	win.attach(grid);
	win.wait_for_button();

	Vector_ref<Rectangle> red_rect;
	for(int xy=0; xy<800; xy+=100){
		red_rect.push_back(new Rectangle{Point{xy,xy}, 100, 100});
		red_rect[red_rect.size()-1].set_fill_color(Color::dark_red);
		win.attach(red_rect[red_rect.size()-1]);	
	}
	win.wait_for_button();
	
	Vector_ref<Image> puppies;
	for(int i=1; i<=3; i++){
		puppies.push_back(new Image{Point{i*200,0}, "dog.jpg"});
		puppies[puppies.size()-1].set_mask(Point{100,0},200,200);
		win.attach(puppies[puppies.size()-1]);
	}
	win.wait_for_button();

	int cat_x=300, cat_y=400, dir_x=1, dir_y=1;
	Image cat {Point{cat_x,cat_y}, "cat.jpg"};
	cat.set_mask(Point{130,70},100,100);
	win.attach(cat);
	while(true){
		win.wait_for_button();
		do{
			if(cat_y+100*dir_y<0 || cat_y+100*dir_y>700){
				dir_y*=-1;
			}
			if(cat_x+100*dir_x<0 || cat_x+100*dir_x>700){
				dir_x*=-1;
				cat.move(0, 100*dir_y);
				cat_y+=100*dir_y;
			}else{
				cat.move(100*dir_x, 0);
				cat_x+=100*dir_x;
			}

		}while(cat_x==cat_y);
		
	}

	
	return 0;
}
catch(exception& e){
	return 1;
}
catch(...){
	return 2;
}