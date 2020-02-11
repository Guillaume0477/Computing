
#include "export_matlab.hpp"

void export_matlab(const std::string& filename,const bezier<float>& b,int sample)
{
    if(sample<1 || sample>50000)
        throw std::exception();

    std::ofstream ofs;
    ofs.open(filename.c_str());

    if(ofs.good()==false)
        throw std::exception();

    ofs<<"polygon=[";
    ofs<<"["<<0<<";"<<b.coeff(0)<<"],";
    ofs<<"["<<1.0/3<<";"<<b.coeff(1)<<"],";
    ofs<<"["<<2.0/3<<";"<<b.coeff(2)<<"],";
    ofs<<"["<<1.0<<";"<<b.coeff(3)<<"]";
    ofs<<"];"<<std::endl;

    ofs<<"curve=[";

    for(int k=0;k<sample;++k)
    {
        float s=static_cast<float>(k)/(sample-1);
        float y=b(s);
        ofs<<"["<<s<<";"<<y<<"]";
        if(k<sample-1)
            ofs<<",";
    }

    ofs<<"];";

    ofs.close();
}


