public class StartLoop implements Command {
	public StartLoop() {}
	@Override
	public void execute(ExecutionContext exc) {
	    if (exc.getElement(exc.getPtr()) == 0) {
            exc.setCommandPtr(exc.getCommandPtr() + 1);
            while (exc.getLoopIndex() > 0 || !(exc.getCommand(exc.getCommandPtr()).equals("]"))) {
                if (exc.getCommand(exc.getCommandPtr()).equals("[")) {
                    exc.setLoopIndex(exc.getLoopIndex() + 1);
                }
                else if (exc.getCommand(exc.getCommandPtr()).equals("]")) {
                    	exc.setLoopIndex(exc.getLoopIndex() - 1);
         	         }
         	    exc.setCommandPtr(exc.getCommandPtr() + 1);
            }
        }    
	}
	@Override
	public String toString() {
		return "[";
	}
}
