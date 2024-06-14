#include<iostream>
#include<math.h>
bool ballInHole(Ball &ball, Hole &hole) {
	if (ball.get_pos_x() >= hole.getHole_x() &&
		ball.get_pos_x() + 2 * ball.getRadius() <= hole.getHole_x() + 2 * hole.getRadius() &&
		ball.get_pos_y() >= hole.getHole_y() &&
		ball.get_pos_y() + 2 * ball.getRadius() <= hole.getHole_y() + 2 * hole.getRadius()) {
		return true;
	}
	else {
		return false;
	}
}

void ball_and_Bar(Ball &ball, Barrier &bar) {
	if (ball.get_pos_x() <= bar.getRect_x() + bar.getWidth() &&
		ball.get_pos_x() + 2 * ball.getRadius() >= bar.getRect_x() &&
		ball.get_pos_y() <= bar.getRect_y() + bar.getHeight() &&
		ball.get_pos_y() + 2 * ball.getRadius() >= bar.getRect_y()) {
		//Right side
		if (ball.get_pos_x() <= bar.getRect_x() + bar.getWidth() &&
			ball.get_pos_y() >= bar.getRect_y() &&
			ball.get_pos_y() + 2 * ball.getRadius() <= bar.getRect_y() + bar.getHeight()) {
			ball.set_dx(-1.f * ball.get_dx());
		}
		//Left side
		else if (ball.get_pos_x() + 2 * ball.getRadius() >= bar.getRect_x() &&
			ball.get_pos_y() >= bar.getRect_y() &&
			ball.get_pos_y() + 2 * ball.getRadius() <= bar.getRect_y() + bar.getHeight()) {
			ball.set_dx(-1.f * ball.get_dx());
		}
		//Bottom side
		else if (ball.get_pos_y() <= bar.getRect_y() + bar.getHeight() &&
			ball.get_pos_x() >= bar.getRect_x() &&
			ball.get_pos_x() + 2 * ball.getRadius() <= bar.getRect_x() + bar.getWidth()) {
			ball.set_dy(-1.f * ball.get_dy());
		}
		//Top side
		else if (ball.get_pos_y() + 2 * ball.getRadius() >= bar.getRect_y() &&
			ball.get_pos_x() >= bar.getRect_x() &&
			ball.get_pos_x() + 2 * ball.getRadius() <= bar.getRect_x() + bar.getWidth()) {
			ball.set_dy(-1.f * ball.get_dy());
		}
	}
}

void ball_movement(Mouse& mouse, Ball& ball) {
	float dis_x = ball.get_pos_x() - mouse.getMouse_x();
	float dis_y = ball.get_pos_y() - mouse.getMouse_y();
	float distance = sqrt((dis_x * dis_x) + (dis_y * dis_y));
	if (ball.get_ddx() == 0.f && ball.get_ddy() == 0.f&&
		ball.get_dx() == 0.f && ball.get_dy() == 0.f) {
		if(distance<=100.f){
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				ball.set_ddx(dis_x * 2.f);
				ball.set_ddy(dis_y * 2.f);
			}
		}
	}
	else {
		if (ball.get_ddx() > 0.f) {
			ball.set_ddx(ball.get_ddx() - ball.get_friction());
			if (ball.get_ddx() < 0.f) {
				ball.set_ddx(0.f);
			}
		}
		else if (ball.get_ddx() < 0.f) {
			ball.set_ddx(ball.get_ddx() + ball.get_friction());
			if (ball.get_ddx() > 0.f) {
				ball.set_ddx(0.f);
			}
		}

		if (ball.get_ddy() > 0.f) {
			ball.set_ddy(ball.get_ddy() - ball.get_friction());
			if (ball.get_ddy() < 0.f) {
				ball.set_ddy(0.f);
			}
		}
		else if (ball.get_ddy() < 0.f) {
			ball.set_ddy(ball.get_ddy() + ball.get_friction());
			if (ball.get_ddy() > 0.f) {
				ball.set_ddy(0.f);
			}
		}
	}
}

void arena_check(Ball& ball) {
	if (ball.get_pos_x() <= 0.f) {
		ball.set_ball_x(0.f);
		ball.set_dx(-1.f * ball.get_dx());
	}
	else if (ball.get_pos_x() >= window.getSize().x - (2 * ball.getRadius())) {
		ball.set_ball_x(window.getSize().x - (2 * ball.getRadius()));
		ball.set_dx(-1.f * ball.get_dx());
	}
	if (ball.get_pos_y() <= 0.f) {
		ball.set_ball_y(0.f);
		ball.set_dy(-1.f * ball.get_dy());
	}
	else if (ball.get_pos_y() >= window.getSize().y - (2 * ball.getRadius())) {
		ball.set_ball_y(window.getSize().y - (2 * ball.getRadius()));
		ball.set_dy(-1.f * ball.get_dy());
	}
}

void displayCount(int count) {
	sf::Font font;
	font.loadFromFile("C:/Users/mehme/OneDrive/Masaüstü/C++ uygulama/2d_golf_game/fonts/Dee-Quickest Sans.otf");
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(45);
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);
	text.setPosition(5,5);
	text.setString("Shot: "+std::to_string(count));
	window.draw(text);
}

void dispPositions(Ball ball,Hole hole,Barrier bar,Mouse mouse) {
	std::cout <<ball.get_ddx()<<", "<<ball.get_ddy() << std::endl;
}