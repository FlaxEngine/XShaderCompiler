/*
 * ASTFactory.h
 * 
 * This file is part of the XShaderCompiler project (Copyright (c) 2014-2016 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef XSC_AST_FACTORY_H
#define XSC_AST_FACTORY_H


#include "AST.h"
#include "TypeDenoter.h"


namespace Xsc
{

namespace ASTFactory
{


// Returns the expression which contains a single expression of the specified type (within brackets), or null if not found.
Expr* FindSingleExpr(Expr* ast, const AST::Types searchedExprType);

FunctionCallPtr FindSingleFunctionCall(Expr* ast);
VarIdentPtr FindSingleVarIdent(Expr* ast);

FunctionCallExprPtr MakeIntrinsicCallExpr(
    const Intrinsic intrinsic, const std::string& ident,
    const TypeDenoterPtr& typeDenoter, const std::vector<ExprPtr>& arguments
);

// Converts the specified function call from "sincos(x, s, c)" to "s = sin(x), c = cos(x)".
ListExprPtr MakeSeparatedSinCosFunctionCalls(FunctionCall& funcCall);

CastExprPtr MakeLiteralCastExpr(const TypeDenoterPtr& typeDenoter, const DataType literalType, const std::string& literalValue);


} // /namespace ASTFactory

} // /namespace Xsc


#endif



// ================================================================================