class Hole{
protected:
	sf::CircleShape circle;
	float hole_pos_x, hole_pos_y;
public:
	Hole(float r, float pos_x, float pos_y)
		:hole_pos_x(pos_x), hole_pos_y(pos_y){
		circle.setRadius(r);
		circle.setPosition(pos_x, pos_y);
		circle.setFillColor(sf::Color::Black);
	}
	
	~Hole() {};
	
	void render_hole(sf::RenderWindow& window) const{
		window.draw(this->circle);
	}

	void setHole_x(float x) { hole_pos_x = x; }
	void setHole_y(float y) { hole_pos_y = y; }
	void setRadius(float r) { circle.setRadius(r); }

	float getHole_x() const{ return hole_pos_x; }
	float getHole_y() const{ return hole_pos_y; }
	float getRadius() const{return circle.getRadius(); }
};