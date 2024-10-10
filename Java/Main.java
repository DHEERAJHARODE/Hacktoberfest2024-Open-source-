import com.amazonaws.AmazonClientException;
import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.auth.AWSStaticCredentialsProvider;
import com.amazonaws.auth.profile.ProfileCredentialsProvider;
import com.amazonaws.services.elasticmapreduce.AmazonElasticMapReduce;
import com.amazonaws.services.elasticmapreduce.AmazonElasticMapReduceClientBuilder;
import com.amazonaws.services.elasticmapreduce.model.*;
import com.amazonaws.services.elasticmapreduce.util.StepFactory;

public class Main {

	public static void main(String[] args) {
		AWSCredentials credentials_profile = null;		
		try {
			credentials_profile = new ProfileCredentialsProvider("default").getCredentials();
        } catch (Exception e) {
            throw new AmazonClientException(
                    "Cannot load credentials from .aws/credentials file. " +
                    "Make sure that the credentials file exists and the profile name is specified within it.",
                    e);
        }
		
		AmazonElasticMapReduce emr = AmazonElasticMapReduceClientBuilder.standard()
			.withCredentials(new AWSStaticCredentialsProvider(credentials_profile))
			.withRegion(Regions.US_WEST_1)
			.build();
        
		// Run a bash script using a predefined step in the StepFactory helper class
	    StepFactory stepFactory = new StepFactory();
	    StepConfig runBashScript = new StepConfig()
	    		.withName("Run a bash script") 
	    		.withHadoopJarStep(stepFactory.newScriptRunnerStep("s3://jeffgoll/emr-scripts/create_users.sh"))
	    		.withActionOnFailure("CONTINUE");

	    // Run a custom jar file as a step
	    HadoopJarStepConfig hadoopConfig1 = new HadoopJarStepConfig()
	       .withJar("s3://path/to/my/jarfolder") // replace with the location of the jar to run as a step
	       .withMainClass("com.my.Main1") // optional main class, this can be omitted if jar above has a manifest
	       .withArgs("--verbose"); // optional list of arguments to pass to the jar
	    StepConfig myCustomJarStep = new StepConfig("RunHadoopJar", hadoopConfig1);

	    AddJobFlowStepsResult result = emr.addJobFlowSteps(new AddJobFlowStepsRequest()
		  .withJobFlowId("j-xxxxxxxxxxxx") // replace with cluster id to run the steps
		  .withSteps(runBashScript,myCustomJarStep));
	    
          System.out.println(result.getStepIds());

	}
}
