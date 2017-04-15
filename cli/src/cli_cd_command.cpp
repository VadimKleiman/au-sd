#include "cli_cd_command.h"
#include <experimental/filesystem>
#include <experimental/fs_path.h>
#include "cli_exception.h"

namespace fs = std::experimental::filesystem;

namespace cli {

const fs::path CdCommand::start = fs::current_path();

CdCommand::CdCommand(std::istream &is, std::ostream &os, const ParamsListType &params)
    : Command(is, os, params)
{}

int CdCommand::run(Environment &env)
{
    (void)env;
    fs::path path;
    if (params_.empty())
    {
        path = this->start;
    }
    else 
    {
        path = fs::u8path(params_[0]);
    }
    if (!fs::exists(path))
    {
        throw CommandException(name(), "directory not found.");
    }
    if (!fs::is_directory(path))
    {
        throw CommandException(name(), path.generic_string() + " is not a directory.");
    }
    fs::current_path(path);
    return 0; 
}
std::string CdCommand::name() const
{
    return "cd";
}
}