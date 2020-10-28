class Date{
    public:
        Date() = default;
        void setDate(int year, char month, char day);
        std::string getDate();        
        ~Date() = default;
    private:
        int year = 1970;
        char month = 1;
        char day = 1;
};

class Parts{
    public:
        Parts() = default;
        float getPartPrice(float currency);
        std::string getPartDescription();        
        ~Parts() = default;
    private:
        std::string description = "Instrument";  
        std::string partNumber = "31323334AA";  
        float price = 95.9;
};