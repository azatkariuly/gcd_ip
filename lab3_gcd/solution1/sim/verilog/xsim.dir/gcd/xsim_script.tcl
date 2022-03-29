set_param project.enableReportConfiguration 0
load_feature core
current_fileset
xsim {gcd} -view {{gcd_dataflow_ana.wcfg}} -tclbatch {gcd.tcl} -protoinst {gcd.protoinst}
