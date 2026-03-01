#pragma once

// Resource represents a generic pool such as Health, Mana, or Stamina.
// It encapsulates a current value and a maximum value and provides
// safe methods to modify and query the resource state.
class Resource {
private:
    int current;  // Current amount of the resource
    int max;      // Maximum amount of the resource

public:
    // Default constructor: creates an empty resource (0 / 0)
    Resource();

    // Parameterized constructor: initializes current and max values
    Resource(int cur, int mx);

    // Accessors for current and maximum values
    int getCurrent() const;
    int getMax() const;

    // Mutators for current and maximum values
    // Implementations clamp values to prevent invalid states
    void setCurrent(int value);
    void setMax(int value);

    // Modifies the resource amount safely
    void restore(int amount);   // Increases current value
    void consume(int amount);   // Decreases current value

    // State queries
    bool isEmpty() const;       // True if current <= 0
    bool isFull() const;        // True if current == max

    // Utility method for UI and gameplay logic
    float getPercentage() const; // Returns current/max as a ratio
};
