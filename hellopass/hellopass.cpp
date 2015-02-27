#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
  struct Hello : public FunctionPass {
    static char ID;
    Hello() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
      errs() << "Hello: ";
      errs().write_escaped(F.getName()) << '\n';
      return false;
    }
  };

  struct HelloBlock : public BasicBlockPass {
    static char ID;
    HelloBlock() : BasicBlockPass(ID) {}

    bool runOnBasicBlock(BasicBlock &blk) {
        for (BasicBlock::iterator i = blk.begin(), e = blk.end(); i != e; ++i)
            errs() << *i << "\n";
    }
  };
}

char Hello::ID = 0;
char HelloBlock::ID = 0;
static RegisterPass<Hello> X("hello", "Hello World Pass", false, false);
static RegisterPass<HelloBlock> Y("helloblock", "Hello World Pass", false, false);
