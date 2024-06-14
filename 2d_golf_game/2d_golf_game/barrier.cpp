class Barrier {
protected:
	sf::RectangleShape rect;
	sf::Color Color;
	float width, height, rect_x, rect_y,rect_dx,rect_dy,dt;
public:
	Barrier(float width,float height, float rectx, float recty,float dx,float dy)
	:width(width),height(height),rect_x(rectx),rect_y(recty),rect_dx(dx),rect_dy(dy), rect(sf::Vector2f(width, height))
	{
		rect.setPosition(rectx, recty);
		rect.setFillColor(Color.Yellow);	
	}

	~Barrier() {};

	void update(float dt) {
		this->dt = dt;
		rect_x = rect.getPosition().x;
		rect_y = rect.getPosition().y;

		rect_x += rect_dx * dt;
		rect_y += rect_dy * dt;

		rect_x += rect_dx * dt;
		rect_y += rect_dy * dt;

		area_check();
		rect.setPosition(rect_x,rect_y);
	}
	
	void area_check() {
		float area_x = window.getSize().x;
		float area_y = window.getSize().y;
		//Right side
		if (rect_x <= 0.f) {
			rect_dx *= -1.f;
		}
		//Left side
		else if (rect_x >= area_x-width) {
			rect_dx *= -1.f;
		}
		//Top side
		if (rect_y <= 0.f) {
			rect_dy *= -1.f;
		}
		//Bottom side
		else if (rect_y >= area_y-height) {
			rect_dy *= -1.f;
		}
	}
	
	void renderBarrier(sf::RenderWindow& window) const{
		window.draw(this->rect);
	}

	void setWidth(float w) {width = w;  }
	void setHeight(float h) {height= h;	}
	void setRect_x(float x) {rect_x= x;	}
	void setRect_y(float y) {rect_y= y;	}
	void setRect_dx(float x) {rect_dx = x; }
	void setRect_dy(float y) {rect_dy = y; }
	void setColor(const sf::Color& color) { Color = color; }

	float getWidth() const{ return width; }
	float getHeight() const{ return height; }
	float getRect_x() const{ return rect_x; }
	float getRect_y() const{ return rect_y; }
	float getRect_dx() const { return rect_dx; }
	float getRect_dy() const { return rect_dy; }
};