class Vehicles
{
public:
    virtual *Vehicles clone() const = 0;
    virtual ~Vehicles() = default;
    virtual printMemberInfor() const = 0;
};