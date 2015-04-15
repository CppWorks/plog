﻿//
// CustomFormatter - this sample shows how to implement a custom formatter.
//

#include <plog/Log.h>

namespace plog
{
    class MyFormatter
    {
    public:
        static util::nstring header() // This method returns a header for a new file. In our case it is empty.
        {
            return util::nstring();
        }

        static util::nstring format(const Record& record) // This method returns a string from a record.
        {
            util::nstringstream ss;
            ss << record.getMessage().c_str() << "\n"; // Produce a simple string with a log message.

            return ss.str();
        }
    };
}

int main()
{
    plog::init<plog::MyFormatter>(plog::debug, "CustomFormatter.txt"); // Pass our custom formatter as a template parameter to init function.

    LOGD << "A debug message!";

    return 0;
}
