extern sf::RenderWindow window;
class Ball {
protected:
	sf::CircleShape circle;
	float ball_pos_x,ball_pos_y,ball_dx, ball_dy, ball_ddx, ball_ddy, friction=100.f, dt;
public:
	Ball(float radius, float posX, float posY, float dx, float dy, float ddx, float ddy, float friction)
		: ball_dx(dx), ball_dy(dy), ball_ddx(ddx), ball_ddy(ddy), friction(friction), dt(0) {
		circle.setRadius(radius);
		circle.setPosition(posX, posY);
		circle.setFillColor(sf::Color::White);
	}

	~Ball() {};

	void update(float dt) {
		this->dt = dt;
		ball_pos_x = circle.getPosition().x ;
		ball_pos_y = circle.getPosition().y ;

		ball_pos_x += ball_dx * dt + 0.5f * ball_ddx * dt * dt;
		ball_dx += ball_ddx * dt;
		
		ball_pos_y += ball_dy * dt + 0.5f * ball_ddy * dt * dt;
		ball_dy += ball_ddy * dt;
		
		if (ball_dx > 0.f) {
			ball_dx -= friction * dt * 100.f;
			if (ball_dx <= 0.01f) {
				ball_dx = 0.f;
			}
		}
		else if (ball_dx < 0.f) {
			ball_dx += friction * dt * 100.f;
			if (ball_dx >= -0.01f) {
				ball_dx = 0.f;
			}
		}
		if (ball_dy > 0.f) {
			ball_dy -= friction * dt * 100.f;
			if (ball_dy <= 0.01f) {
				ball_dy = 0.f;
			}
		}
		else if (ball_dy < 0.f) {
			ball_dy += friction * dt * 100.f;
			if (ball_dy >= -0.01f) {
				ball_dy = 0.f;
			}
		}

		circle.setPosition(ball_pos_x, ball_pos_y);
	}
	
	void render(sf::RenderWindow& window) const{
		window.draw(this->circle);
	}

	void set_ball_x(float x) { ball_pos_x = x; }
	void set_ball_y(float y) { ball_pos_y = y; }
	void set_dx(float dx) { ball_dx = dx; }
	void set_dy(float dy) { ball_dy = dy; }
	void set_ddx(float ddx) { ball_ddx = ddx; }
	void set_ddy(float ddy) { ball_ddy = ddy; }
	void set_friction(float f) { friction = f; }
	void setRadius(float r) { circle.setRadius(r); }

	float get_pos_x() const{ return ball_pos_x; }
	float get_pos_y() const{ return ball_pos_y; }
	float get_dx() const{ return ball_dx; }
	float get_dy() const{ return ball_dy; }
	float get_ddx() const{ return ball_ddx; }
	float get_ddy() const{ return ball_ddy; }
	float get_friction() const { return friction; }
	float getRadius() const { return circle.getRadius();}
};