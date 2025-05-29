void task1_b() {
    // Create a canvas 
    auto c1 = new TCanvas("c1", "Gaussian Distribution", 800, 600);
    
    // 1) Create a 1D histogram
    auto h = new TH1F("h", "Gaussian Distribution; x; Counts", 100, -25, 25);
    
    // 2) Generate N=1000 random values from Gaussian(mean = -1, sigma = 5)
    TRandom3 randGen; // ROOT random number generator
    int N = 1000;
    for (int i = 0; i < N; i++) {
        float val = randGen.Gaus(-1, 5); // mean = -1, sigma = 5
        h->Fill(val);
    }
    
    // 3) Fit the histogram with a Gaussian function
    auto gausFit = new TF1("gausFit", "gaus", -25, 25);
    h->Fit(gausFit); 
    
    // Get fit parameters and uncertainties
    double mean = gausFit->GetParameter(1);
    double sigma = gausFit->GetParameter(2);
    double meanErr = gausFit->GetParError(1);
    double sigmaErr = gausFit->GetParError(2);
    
    // Print results
    printf("Fit results:\n");
    printf("Mean = %f ± %f\n", mean, meanErr);
    printf("Sigma = %f ± %f\n", sigma, sigmaErr);
    
    // Draw the histogram and fit
    h->Draw();
    gausFit->Draw("same");
    
    // Update the canvas to make sure everything is displayed
    c1->Update();
    c1->Draw();
}