#ifndef BATTERY_H
#define BATTERY_H

/// class Battery -
class Battery {
  // Attributes
private:
  int limit;
  int power;
  // Operations
public:
  Battery(int limit);
  int getPower ();
  void setPower (int power);
};
#endif // BATTERY_H
