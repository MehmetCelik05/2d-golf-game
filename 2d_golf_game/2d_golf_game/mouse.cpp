class Mouse {
protected:
	sf::Mouse mouse;
public:
	Mouse() :mouse() {}

	float getMouse_x() const{ return mouse.getPosition(window).x; }
	float getMouse_y() const{ return mouse.getPosition(window).y; }
};