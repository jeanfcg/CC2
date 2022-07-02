class Point
{
    private:
        float x, y;
    public:
        Point(){}
        ~Point(){}
        void setPoints(float x, float y){
            this->x = x;
            this->y = y;
        }

        float getX(){return x;}
        float getY(){return y;}
};
