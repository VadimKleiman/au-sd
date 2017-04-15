#ifndef CLI_LS_COMMAND_H
#define CLI_LS_COMMAND_H

#include "cli_command.h"

namespace cli {
/**
 * @brief List directory contents.
 */
class LsCommand : public Command
{
public:
    /**
     * @brief PwdCommand constructor
     * @param is input stream.
     * @param os output stream.
     * @param params command line parameters.
     */
    LsCommand(std::istream &is, std::ostream &os, const ParamsListType &params);
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
};

} // namespace cli

#endif // CLI_LS_COMMAND_H
