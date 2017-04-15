#pragma once
#ifndef CLI_CD_COMMAND_TEST_H
#define CLI_CD_COMMAND_TEST_H

#include <cxxtest/TestSuite.h>
#include "cli_cd_command.h"
#include <experimental/filesystem>

#include <vector>
#include <string>
#include <sstream>

namespace fs = std::experimental::filesystem;

class CdCommandTest : public CxxTest::TestSuite
{
public:
    void testSimple()
    {
        std::string dir = fs::temp_directory_path().generic_string();
        std::istringstream is;
        std::ostringstream os;
        cli::CdCommand cd(is, os, {dir});
        cd.run(empty_env_);
        std::string current = fs::current_path().generic_string();
        TS_ASSERT_EQUALS(dir, current);
    }
private:
    cli::Environment empty_env_;
};


#endif // CLI_CD_COMMAND_TEST_H