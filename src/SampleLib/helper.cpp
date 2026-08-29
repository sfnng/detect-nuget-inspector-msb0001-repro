#include <string>
#include <zlib.h>

std::string compress_string(const std::string& input)
{
    uLongf dest_len = compressBound(input.size());
    std::string output(dest_len, '\0');
    compress(reinterpret_cast<Bytef*>(&output[0]), &dest_len,
             reinterpret_cast<const Bytef*>(input.data()), input.size());
    output.resize(dest_len);
    return output;
}
