// File: bdi/optimizer/OptimizationPassBase.hpp
 #ifndef BDI_OPTIMIZER_OPTIMIZATIONPASSBASE_HPP
 #define BDI_OPTIMIZER_OPTIMIZATIONPASSBASE_HPP
 #include "GraphVisitor.hpp"
 #include <string>
 namespace bdi::optimizer {
 // Base class for optimization passes, inheriting from GraphVisitor
 class OptimizationPassBase : public GraphVisitor {
 public:
    explicit OptimizationPassBase(std::string pass_name)
        : name_(std::move(pass_name)), graph_modified_(false) {}
    virtual ~OptimizationPassBase() override = default;
    // Run the optimization pass on the graph
    virtual bool run(BDIGraph& graph) {
        graph_modified_ = false; // Reset modification flag
        visitGraph(graph);       // Execute the visit logic
        return graph_modified_;  // Return whether the graph was changed
    }
    const std::string& getName() const { return name_; }
 protected:
    // Helper for derived classes to signal modification
    void markGraphModified() { graph_modified_ = true; }
    bool wasGraphModified() const { return graph_modified_; }
 private:
    std::string name_;
    bool graph_modified_;
 };
 } // namespace bdi::optimizer
 #endif // BDI_OPTIMIZER_OPTIMIZATIONPASSBASE_HPP
