#include "cli_ls_command.h"
#include <experimental/filesystem>
#include <experimental/fs_path.h>
#include <iostream>
#include "cli_exception.h"

namespace fs = std::experimental::filesystem;

namespace cli {

LsCommand::LsCommand(std::istream &is, std::ostream &os, const ParamsListType &params)
    : Command(is, os, params)
{}

int LsCommand::run(Environment &env)
{
    (void)env;
    for (auto it = params_.cbegin(); it != params_.cend(); ++it)
    {
        auto path = fs::u8path(*it);
        os_ << *it << ":" << std::endl;
        if (!fs::exists(path))
        {
            throw CommandException(name(), "file not found.");
        }
        if (!fs::is_directory(path))
        {
            os_ << path.generic_string() << std::endl;
        }
        else
        {
            for (const auto& i: fs::directory_iterator(path))
            {
                os_ << i.path().filename().generic_string() << std::endl;
            }
        }
    }
    if (params_.empty()) {
        for (const auto& i: fs::directory_iterator(fs::current_path()))
        {
            os_ << i.path().filename().generic_string() << std::endl;
        }
    }
    return 0;
}
std::string LsCommand::name() const
{
    return "ls";
}
}