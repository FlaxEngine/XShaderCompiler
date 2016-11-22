/*
 * GLSLConverter.h
 * 
 * This file is part of the XShaderCompiler project (Copyright (c) 2014-2016 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef XSC_GLSL_CONVERTER_H
#define XSC_GLSL_CONVERTER_H


#include "Visitor.h"
#include <Xsc/Targets.h>
#include <functional>
#include <set>


namespace Xsc
{


// GLSL AST converter.
class GLSLConverter : public Visitor
{
    
    public:
        
        // Converts the specified AST for GLSL.
        void Convert(
            Program& program,
            const ShaderTarget shaderTarget,
            const std::string& nameManglingPrefix
        );

    private:
        
        /* --- Visitor implementation --- */

        DECL_VISIT_PROC( Program      );
        DECL_VISIT_PROC( FunctionCall );
        DECL_VISIT_PROC( StructDecl   );
        DECL_VISIT_PROC( VarIdent     );

        DECL_VISIT_PROC( VarDecl      );

        DECL_VISIT_PROC( FunctionDecl );

        DECL_VISIT_PROC( ExprStmnt    );

        DECL_VISIT_PROC( LiteralExpr  );
        DECL_VISIT_PROC( UnaryExpr    );

        /* --- Helper functions for conversion --- */

        void PushStructDeclLevel();
        void PopStructDeclLevel();

        bool IsInsideStructDecl() const;

        // Returns true if the specified expression contains a sampler object.
        bool ExprContainsSampler(Expr& ast) const;

        // Returns true if the specified variable type is a sampler.
        bool VarTypeIsSampler(VarType& ast) const;

        // Returns true if the specified structure declaration must be resolved.
        bool MustResolveStruct(StructDecl* ast) const;

        // Returns true if the specified variable declaration must be renamed.
        bool MustRenameVarDecl(VarDecl* ast) const;

        // Renames the specified variable declaration with name mangling.
        void RenameVarDecl(VarDecl* ast);

        // Returns true if the variable identifier refers to a variable declaration which has a system semantic.
        bool HasVarDeclOfVarIdentSystemSemantic(VarIdent* varIdent) const;

        /*
        Changes the specified variable identifier to a local variable identifier
        (without a leading structure instance name), if it refers to a variable with a system semantic.
        */
        void MakeVarIdentWithSystemSemanticLocal(VarIdent* ast);

        /* === Members === */

        ShaderTarget                shaderTarget_       = ShaderTarget::VertexShader;

        std::string                 nameManglingPrefix_;

        /*
        List of all reserved variable identifiers that come from a structure that must be resolved.
        If a local variable uses a name from this list, it name must be modified with name mangling.
        */
        std::vector<std::string>    reservedVarIdents_;

        unsigned int                structDeclLevel_    = 0;

};


} // /namespace Xsc


#endif



// ================================================================================