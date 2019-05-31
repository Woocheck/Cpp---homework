/*
Extend a class by having operators:

+ (addition)
- (subtraction)
* (multiplication)
/ (division)

+= (addition-assignment)
-= (subtraction-assignment)
*= (multiplication-assignment)
/= (division-assignment)
*/



template<typename T>
class Vector3d {
public:
    Vector3d(T x, T y, T z) :
            x_(x), y_(y), z_(z) {
    }

    Vector3d<T>& operator+=(const Vector3d<T>& rhs) 
    {
        x_ += rhs.x_;
        y_ += rhs.y_;
        z_ += rhs.z_;
        return *this;
    }

    Vector3d<T>& operator-=(const Vector3d<T>& rhs) 
    {
        x_ -= rhs.x_;
        y_ -= rhs.y_;
        z_ -= rhs.z_;
        return *this;
    }

    Vector3d<T>& operator*=(const T& rhs) 
    {
        x_ *= rhs;
        y_ *= rhs;
        z_ *= rhs;
        return *this;
    }

    Vector3d<T>& operator*=(const Vector3d<T>& rhs) 
    {
        Vector3d<T> product(0,0,0);
        product.setX( ( y_ * rhs.getZ() ) - ( z_ * rhs.getY() ) );
        product.setY( ( z_ * rhs.getX() ) - ( x_ * rhs.getZ() ) );
        product.setZ( ( x_ * rhs.getY() ) - ( y_ * rhs.getX() ) );
        x_ = product.getX();
        y_ = product.getY();
        z_ = product.getZ();
        return *this;
    }

    Vector3d<T>& operator/=(const T& rhs) {
        try
        {   
            if( rhs == 0 )
                throw std::overflow_error("Divide by zero exception");
            x_ /= rhs;
            y_ /= rhs;
            z_ /= rhs;
        return *this;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return *this;
    }
    
    Vector3d<T>& operator+(const Vector3d<T>& rhs) {
        return *this += rhs;
    }

    Vector3d<T>& operator-(const Vector3d<T>& rhs) {
        return *this -= rhs;
    }

    Vector3d<T>& operator*(const Vector3d<T>& rhs) {
        return *this *= rhs;
    }

     Vector3d<T>& operator*(const T& rhs) {
        return *this *= rhs;
    }

    Vector3d<T>& operator/(const T& rhs) {
       
      if( rhs == 0)
          throw std::overflow_error("Divide by zero exception");
      return *this/=rhs;
       

       
    }

    

    T getX() const { return x_; }
    T getY() const { return y_; }
    T getZ() const { return z_; }

    void setX( T a ) { x_ = a; }
    void setY( T b ) { y_ = b; }
    void setZ( T c ) { z_ = c; }


private:
    T x_;
    T y_;
    T z_;
    
};

