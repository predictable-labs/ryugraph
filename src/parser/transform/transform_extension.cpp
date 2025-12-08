#include "extension/extension.h"
#include "parser/extension_statement.h"
#include "parser/transformer.h"

using namespace ryu::common;
using namespace ryu::extension;

namespace ryu {
namespace parser {

std::unique_ptr<Statement> Transformer::transformExtension(CypherParser::RU_ExtensionContext& ctx) {
    if (ctx.rU_InstallExtension()) {
        auto extensionRepo =
            ctx.rU_InstallExtension()->StringLiteral() ?
                transformStringLiteral(*ctx.rU_InstallExtension()->StringLiteral()) :
                ExtensionUtils::OFFICIAL_EXTENSION_REPO;

        auto installExtensionAuxInfo = std::make_unique<InstallExtensionAuxInfo>(
            std::move(extensionRepo), transformVariable(*ctx.rU_InstallExtension()->oC_Variable()),
            ctx.rU_InstallExtension()->FORCE());
        return std::make_unique<ExtensionStatement>(std::move(installExtensionAuxInfo));
    } else if (ctx.rU_UpdateExtension()) {
        // Update extension is a syntax sugar for force install extension.
        auto installExtensionAuxInfo = std::make_unique<InstallExtensionAuxInfo>(
            ExtensionUtils::OFFICIAL_EXTENSION_REPO,
            transformVariable(*ctx.rU_UpdateExtension()->oC_Variable()), true /* forceInstall */);
        return std::make_unique<ExtensionStatement>(std::move(installExtensionAuxInfo));
    } else if (ctx.rU_UninstallExtension()) {
        auto path = transformVariable(*ctx.rU_UninstallExtension()->oC_Variable());
        return std::make_unique<ExtensionStatement>(
            std::make_unique<ExtensionAuxInfo>(ExtensionAction::UNINSTALL, std::move(path)));
    } else {
        auto path = ctx.rU_LoadExtension()->StringLiteral() ?
                        transformStringLiteral(*ctx.rU_LoadExtension()->StringLiteral()) :
                        transformVariable(*ctx.rU_LoadExtension()->oC_Variable());
        auto installExtensionAuxInfo =
            std::make_unique<ExtensionAuxInfo>(ExtensionAction::LOAD, std::move(path));
        return std::make_unique<ExtensionStatement>(std::move(installExtensionAuxInfo));
    }
}

} // namespace parser
} // namespace ryu
