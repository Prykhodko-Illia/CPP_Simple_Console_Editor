#ifndef FRAME_H
#define FRAME_H



class Frame {
protected:
    int scopeId = 0;
public:
    virtual void printContent() = 0;

    [[nodiscard]] int getScopeId() const {
        return scopeId;
    }

    virtual ~Frame() = default;
};



#endif //FRAME_H
