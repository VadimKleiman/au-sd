#ifndef CLI_CD_COMMAND_H
#define CLI_CD_COMMAND_H
#include <experimental/filesystem>
#include "cli_command.h"

namespace fs = std::experimental::filesystem;

namespace cli {
/**
 * @brief Command used to change the current working directory.
 */
class CdCommand : public Command
{
public:
    /**
     * @brief PwdCommand constructor
     * @param is input stream.
     * @param os output stream.
     * @param params command line parameters.
     */
    CdCommand(std::istream &is, std::ostream &os, const ParamsListType &params);
    /**
     * @brief run entering point for the command.
     * @param env environment.
     * @return exit code (bash like).
     */
    int run(Environment &env) override;
    /**
     * @brief name helper function helps identify the type of command object.
     * @return name of the command object.
     */
    std::string name() const override;
    const static fs::path start;
};

} // namespace cli

#endif // CLI_LS_COMMAND_H
