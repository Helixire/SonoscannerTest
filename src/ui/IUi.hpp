#ifndef IUI_HPP
#define IUI_HPP

class IUi {
 public:
  virtual ~IUi() = default;
  virtual void processEvent() = 0;
  virtual bool shouldStop() = 0;
};

#endif  // IUI_HPP
