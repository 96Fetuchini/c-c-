class Glyph{
    //Appearance
    virtual void Draw(/*Window**/) = 0;
    virtual void Bounds(Glyph*) = 0;
    //hit detection
    virtual bool Intersects(/*const Point& */) = 0;
    //structure 
    virtual void Insert(Glyph*, int) = 0;
    virtual void Remove(Glyph*) = 0;
    virtual Glyph* Child(int) = 0;
    virtual Glyph* Parent() = 0;
};