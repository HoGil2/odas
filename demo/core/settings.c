
	#include "settings.h"

	settings * settings_construct(void) {

		settings * sets;

		sets = (settings *) malloc(sizeof(settings));
				
		return sets;

	}

	void settings_destroy(settings * sets) {

		free((void *) sets);

	}

	void settings_load(settings * sets, const char * file) {

		json_tokens * tokens;
		char * line;
		char * string;
		FILE * fp;
		char * rtnPtr;

		unsigned int nTokens = 4096;
		unsigned int nBytesPerLine = 1024;
		unsigned int nBytesPerString = 65536;

		int parseRtn;

		int token_root_O;

		int token_root_general_V;
		int token_root_general_O;
		
		int token_root_general_epsilon_V;
		int token_root_general_epsilon_N;
		
		int token_root_general_size_V;
		int token_root_general_size_O;
		int token_root_general_size_hopSize_V;
		int token_root_general_size_hopSize_N;
		int token_root_general_size_frameSize_V;
		int token_root_general_size_frameSize_N;
		
		int token_root_general_samplerate_V;
		int token_root_general_samplerate_O;
		int token_root_general_samplerate_mu_V;
		int token_root_general_samplerate_mu_N;
		int token_root_general_samplerate_sigma2_V;
		int token_root_general_samplerate_sigma2_N;
		
		int token_root_general_speedofsound_V;
		int token_root_general_speedofsound_O;
		int token_root_general_speedofsound_mu_V;
		int token_root_general_speedofsound_mu_N;
		int token_root_general_speedofsound_sigma2_V;
		int token_root_general_speedofsound_sigma2_N;
		
		int token_root_general_mics_V;
		int token_root_general_mics_A;
		int token_root_general_mics_e_V[SETTINGS_NMICS];
		int token_root_general_mics_e_O[SETTINGS_NMICS];
		int token_root_general_mics_e_mus_V[SETTINGS_NMICS];
		int token_root_general_mics_e_mus_A[SETTINGS_NMICS];
		int token_root_general_mics_e_mus_0_V[SETTINGS_NMICS];
		int token_root_general_mics_e_mus_0_N[SETTINGS_NMICS];
		int token_root_general_mics_e_mus_1_V[SETTINGS_NMICS];
		int token_root_general_mics_e_mus_1_N[SETTINGS_NMICS];
		int token_root_general_mics_e_mus_2_V[SETTINGS_NMICS];
		int token_root_general_mics_e_mus_2_N[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_V[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_A[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_0_V[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_0_N[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_1_V[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_1_N[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_2_V[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_2_N[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_3_V[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_3_N[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_4_V[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_4_N[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_5_V[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_5_N[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_6_V[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_6_N[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_7_V[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_7_N[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_8_V[SETTINGS_NMICS];
		int token_root_general_mics_e_sigma2s_8_N[SETTINGS_NMICS];
		int token_root_general_mics_e_directions_V[SETTINGS_NMICS];
		int token_root_general_mics_e_directions_A[SETTINGS_NMICS];
		int token_root_general_mics_e_directions_0_V[SETTINGS_NMICS];
		int token_root_general_mics_e_directions_0_N[SETTINGS_NMICS];
		int token_root_general_mics_e_directions_1_V[SETTINGS_NMICS];
		int token_root_general_mics_e_directions_1_N[SETTINGS_NMICS];
		int token_root_general_mics_e_directions_2_V[SETTINGS_NMICS];
		int token_root_general_mics_e_directions_2_N[SETTINGS_NMICS];
		int token_root_general_mics_e_angles_V[SETTINGS_NMICS];
		int token_root_general_mics_e_angles_A[SETTINGS_NMICS];
		int token_root_general_mics_e_angles_0_V[SETTINGS_NMICS];
		int token_root_general_mics_e_angles_0_N[SETTINGS_NMICS];
		int token_root_general_mics_e_angles_1_V[SETTINGS_NMICS];
		int token_root_general_mics_e_angles_1_N[SETTINGS_NMICS];

		int token_root_general_spatialfilters_V;
		int token_root_general_spatialfilters_A;
		int token_root_general_spatialfilters_e_V[SETTINGS_NSPATIALFILTERS];
		int token_root_general_spatialfilters_e_O[SETTINGS_NSPATIALFILTERS];
		int token_root_general_spatialfilters_e_directions_V[SETTINGS_NSPATIALFILTERS];
		int token_root_general_spatialfilters_e_directions_A[SETTINGS_NSPATIALFILTERS];
		int token_root_general_spatialfilters_e_directions_0_V[SETTINGS_NSPATIALFILTERS];
		int token_root_general_spatialfilters_e_directions_0_N[SETTINGS_NSPATIALFILTERS];
		int token_root_general_spatialfilters_e_directions_1_V[SETTINGS_NSPATIALFILTERS];
		int token_root_general_spatialfilters_e_directions_1_N[SETTINGS_NSPATIALFILTERS];
		int token_root_general_spatialfilters_e_directions_2_V[SETTINGS_NSPATIALFILTERS];
		int token_root_general_spatialfilters_e_directions_2_N[SETTINGS_NSPATIALFILTERS];
		int token_root_general_spatialfilters_e_angles_V[SETTINGS_NSPATIALFILTERS];
		int token_root_general_spatialfilters_e_angles_A[SETTINGS_NSPATIALFILTERS];
		int token_root_general_spatialfilters_e_angles_0_V[SETTINGS_NSPATIALFILTERS];
		int token_root_general_spatialfilters_e_angles_0_N[SETTINGS_NSPATIALFILTERS];
		int token_root_general_spatialfilters_e_angles_1_V[SETTINGS_NSPATIALFILTERS];
		int token_root_general_spatialfilters_e_angles_1_N[SETTINGS_NSPATIALFILTERS];

		int token_root_general_nthetas_V;
		int token_root_general_nthetas_N;
		int token_root_general_gainmin_V;
		int token_root_general_gainmin_N;

		int token_root_sne_V;
		int token_root_sne_O;

		int token_root_sne_b_V;
		int token_root_sne_b_N;
		int token_root_sne_alphaS_V;
		int token_root_sne_alphaS_N;
		int token_root_sne_L_V;
		int token_root_sne_L_N;
		int token_root_sne_delta_V;
		int token_root_sne_delta_N;
		int token_root_sne_alphaD_V;
		int token_root_sne_alphaD_N;

		int token_root_ssl_V;
		int token_root_ssl_O;

		int token_root_ssl_nPots_V;
		int token_root_ssl_nPots_N;
		int token_root_ssl_nMatches_V;
		int token_root_ssl_nMatches_N;
		int token_root_ssl_probMin_V;
		int token_root_ssl_probMin_N;
		int token_root_ssl_nRefinedLevels_V;
		int token_root_ssl_nRefinedLevels_N;
		int token_root_ssl_interpRate_V;
		int token_root_ssl_interpRate_N;

		int token_root_ssl_scans_V;
		int token_root_ssl_scans_A;
		int token_root_ssl_scans_e_V[SETTINGS_NSCANS];
		int token_root_ssl_scans_e_O[SETTINGS_NSCANS];
		int token_root_ssl_scans_e_level_V[SETTINGS_NSCANS];
		int token_root_ssl_scans_e_level_N[SETTINGS_NSCANS];
		int token_root_ssl_scans_e_delta_V[SETTINGS_NSCANS];
		int token_root_ssl_scans_e_delta_N[SETTINGS_NSCANS];

		int token_root_sst_V;
		int token_root_sst_O;

		int token_root_sst_mode_V;
		int token_root_sst_mode_S;
		int token_root_sst_add_V;
		int token_root_sst_add_S;

		int token_root_sst_energy_V;
		int token_root_sst_energy_O;
		int token_root_sst_energy_active_V;
		int token_root_sst_energy_active_A;
		int token_root_sst_energy_active_e_V[SETTINGS_NGAUSSIANS];
		int token_root_sst_energy_active_e_O[SETTINGS_NGAUSSIANS];
		int token_root_sst_energy_active_e_weight_V[SETTINGS_NGAUSSIANS];
		int token_root_sst_energy_active_e_weight_N[SETTINGS_NGAUSSIANS];
		int token_root_sst_energy_active_e_mu_V[SETTINGS_NGAUSSIANS];
		int token_root_sst_energy_active_e_mu_N[SETTINGS_NGAUSSIANS];
		int token_root_sst_energy_active_e_sigma2_V[SETTINGS_NGAUSSIANS];
		int token_root_sst_energy_active_e_sigma2_N[SETTINGS_NGAUSSIANS];
		int token_root_sst_energy_inactive_V;
		int token_root_sst_energy_inactive_A;
		int token_root_sst_energy_inactive_e_V[SETTINGS_NGAUSSIANS];
		int token_root_sst_energy_inactive_e_O[SETTINGS_NGAUSSIANS];
		int token_root_sst_energy_inactive_e_weight_V[SETTINGS_NGAUSSIANS];
		int token_root_sst_energy_inactive_e_weight_N[SETTINGS_NGAUSSIANS];
		int token_root_sst_energy_inactive_e_mu_V[SETTINGS_NGAUSSIANS];
		int token_root_sst_energy_inactive_e_mu_N[SETTINGS_NGAUSSIANS];
		int token_root_sst_energy_inactive_e_sigma2_V[SETTINGS_NGAUSSIANS];
		int token_root_sst_energy_inactive_e_sigma2_N[SETTINGS_NGAUSSIANS];
		
		int token_root_sst_sigmaR2_V;
		int token_root_sst_sigmaR2_O;
		int token_root_sst_sigmaR2_prob_V;
		int token_root_sst_sigmaR2_prob_N;
		int token_root_sst_sigmaR2_active_V;
		int token_root_sst_sigmaR2_active_N;
		int token_root_sst_sigmaR2_target_V;
		int token_root_sst_sigmaR2_target_N;

		int token_root_sst_P_V;
		int token_root_sst_P_O;
		int token_root_sst_P_false_V;
		int token_root_sst_P_false_N;
		int token_root_sst_P_new_V;
		int token_root_sst_P_new_N;
		int token_root_sst_P_track_V;
		int token_root_sst_P_track_N;

		int token_root_sst_levels_V;
		int token_root_sst_levels_O;
		int token_root_sst_levels_new_V;
		int token_root_sst_levels_new_O;
		int token_root_sst_levels_new_theta_V;
		int token_root_sst_levels_new_theta_N;
		int token_root_sst_levels_prob_V;
		int token_root_sst_levels_prob_O;
		int token_root_sst_levels_prob_theta_V;
		int token_root_sst_levels_prob_theta_N;
		int token_root_sst_levels_prob_N_V;
		int token_root_sst_levels_prob_N_N;
		int token_root_sst_levels_inactive_V;
		int token_root_sst_levels_inactive_O;
		int token_root_sst_levels_inactive_theta_V;
		int token_root_sst_levels_inactive_theta_N;
		int token_root_sst_levels_inactive_Ns_V;
		int token_root_sst_levels_inactive_Ns_A;
		int token_root_sst_levels_inactive_Ns_e_V[SETTINGS_NLEVELS];
		int token_root_sst_levels_inactive_Ns_e_N[SETTINGS_NLEVELS];

		int token_root_sst_kalman_V;
		int token_root_sst_kalman_O;
		int token_root_sst_kalman_sigmaQ_V;
		int token_root_sst_kalman_sigmaQ_N;

		int token_root_sst_particle_V;
		int token_root_sst_particle_O;
		int token_root_sst_particle_nParticles_V;
		int token_root_sst_particle_nParticles_N;
		int token_root_sst_particle_stationary_V;
		int token_root_sst_particle_stationary_O;
		int token_root_sst_particle_stationary_alpha_V;
		int token_root_sst_particle_stationary_alpha_N;
		int token_root_sst_particle_stationary_beta_V;
		int token_root_sst_particle_stationary_beta_N;
		int token_root_sst_particle_stationary_ratio_V;
		int token_root_sst_particle_stationary_ratio_N;
		int token_root_sst_particle_velocity_V;
		int token_root_sst_particle_velocity_O;
		int token_root_sst_particle_velocity_alpha_V;
		int token_root_sst_particle_velocity_alpha_N;
		int token_root_sst_particle_velocity_beta_V;
		int token_root_sst_particle_velocity_beta_N;
		int token_root_sst_particle_velocity_ratio_V;
		int token_root_sst_particle_velocity_ratio_N;
		int token_root_sst_particle_acceleration_V;
		int token_root_sst_particle_acceleration_O;
		int token_root_sst_particle_acceleration_alpha_V;
		int token_root_sst_particle_acceleration_alpha_N;
		int token_root_sst_particle_acceleration_beta_V;
		int token_root_sst_particle_acceleration_beta_N;
		int token_root_sst_particle_acceleration_ratio_V;
		int token_root_sst_particle_acceleration_ratio_N;
		int token_root_sst_particle_Nmin_V;
		int token_root_sst_particle_Nmin_N;

		int token_root_sss_V;
		int token_root_sss_O;

		int token_root_sss_offset_V;
		int token_root_sss_offset_N;

		int token_root_sss_separation_V;
		int token_root_sss_separation_O;

		int token_root_sss_separation_mode_V;
		int token_root_sss_separation_mode_S;
		int token_root_sss_separation_techniques_V;
		int token_root_sss_separation_techniques_O;
		int token_root_sss_separation_techniques_dds_V;
		int token_root_sss_separation_techniques_dds_O;
		int token_root_sss_separation_techniques_dgss_V;
		int token_root_sss_separation_techniques_dgss_O;
		int token_root_sss_separation_techniques_dgss_mu_V;
		int token_root_sss_separation_techniques_dgss_mu_N;
		int token_root_sss_separation_techniques_dgss_lambda_V;
		int token_root_sss_separation_techniques_dgss_lambda_N;
		int token_root_sss_separation_techniques_dmvdr_V;
		int token_root_sss_separation_techniques_dmvdr_O;
		int token_root_sss_separation_format_V;
		int token_root_sss_separation_format_O;
		int token_root_sss_separation_format_fS_V;
		int token_root_sss_separation_format_fS_N;
		int token_root_sss_separation_format_hopSize_V;
		int token_root_sss_separation_format_hopSize_N;
		int token_root_sss_separation_format_nBits_V;
		int token_root_sss_separation_format_nBits_N;	

		int token_root_sss_postfiltering_V;
		int token_root_sss_postfiltering_O;

		int token_root_sss_postfiltering_mode_V;
		int token_root_sss_postfiltering_mode_S;
		int token_root_sss_postfiltering_techniques_V;
		int token_root_sss_postfiltering_techniques_O;
		int token_root_sss_postfiltering_techniques_ms_V;
		int token_root_sss_postfiltering_techniques_ms_O;
		int token_root_sss_postfiltering_techniques_ms_alphaPmin_V;
		int token_root_sss_postfiltering_techniques_ms_alphaPmin_N;
		int token_root_sss_postfiltering_techniques_ms_eta_V;
		int token_root_sss_postfiltering_techniques_ms_eta_N;
		int token_root_sss_postfiltering_techniques_ms_alphaZ_V;
		int token_root_sss_postfiltering_techniques_ms_alphaZ_N;
		int token_root_sss_postfiltering_techniques_ms_thetaWin_V;
		int token_root_sss_postfiltering_techniques_ms_thetaWin_N;
		int token_root_sss_postfiltering_techniques_ms_alphaWin_V;
		int token_root_sss_postfiltering_techniques_ms_alphaWin_N;
		int token_root_sss_postfiltering_techniques_ms_maxAbsenceProb_V;
		int token_root_sss_postfiltering_techniques_ms_maxAbsenceProb_N;
		int token_root_sss_postfiltering_techniques_ms_Gmin_V;
		int token_root_sss_postfiltering_techniques_ms_Gmin_N;
		int token_root_sss_postfiltering_techniques_ms_winSizeLocal_V;
		int token_root_sss_postfiltering_techniques_ms_winSizeLocal_N;
		int token_root_sss_postfiltering_techniques_ms_winSizeGlobal_V;
		int token_root_sss_postfiltering_techniques_ms_winSizeGlobal_N;
		int token_root_sss_postfiltering_techniques_ms_winSizeFrame_V;
		int token_root_sss_postfiltering_techniques_ms_winSizeFrame_N;
		int token_root_sss_postfiltering_techniques_ss_V;
		int token_root_sss_postfiltering_techniques_ss_O;
		int token_root_sss_postfiltering_techniques_ss_Gmin_V;
		int token_root_sss_postfiltering_techniques_ss_Gmin_N;
		int token_root_sss_postfiltering_techniques_ss_Gmid_V;
		int token_root_sss_postfiltering_techniques_ss_Gmid_N;
		int token_root_sss_postfiltering_techniques_ss_Gslope_V;
		int token_root_sss_postfiltering_techniques_ss_Gslope_N;
		int token_root_sss_postfiltering_format_V;
		int token_root_sss_postfiltering_format_O;
		int token_root_sss_postfiltering_format_fS_V;
		int token_root_sss_postfiltering_format_fS_N;
		int token_root_sss_postfiltering_format_hopSize_V;
		int token_root_sss_postfiltering_format_hopSize_N;
		int token_root_sss_postfiltering_format_nBits_V;
		int token_root_sss_postfiltering_format_nBits_N;	

		unsigned int iMic, nMics;
		unsigned int iSpatialFilter, nSpatialFilters;
		unsigned int iScan, nScans;
		unsigned int iGaussianActive, nGaussiansActive;
		unsigned int iGaussianInactive, nGaussiansInactive;
		unsigned int iLevel, nLevels;

		// Allocate

		tokens = json_tokens_construct(nTokens);
		line = (char *) malloc(sizeof(char) * nBytesPerLine);
		string = (char *) malloc(sizeof(char) * nBytesPerString);

		// Load file in a string
		
		fp = fopen(file, "r");
		string[0] = 0x00;
		if (fp == NULL) { printf("Cannot open file %s\n", file); exit(EXIT_FAILURE); }
		while(feof(fp)==0) {
			line[0] = 0x00;
			rtnPtr = fgets(line, nBytesPerLine, fp);
			if ((strlen(line) + strlen(string)) > nBytesPerString) { printf("Buffer overflow while loading JSON\n"); exit(EXIT_FAILURE); }
			strcat(string, line);
		}
		fclose(fp);
		
		// Parse
		
		json_tokens_clear(tokens);
		parseRtn = json_tokens_parse(tokens, string);
		if (parseRtn == -1) { printf("JSON file has invalid format\n"); exit(EXIT_FAILURE); }

		// Reference each token
		
		token_root_O = json_tokens_getFromValue(tokens, string, -1); settings_validate(token_root_O);

		token_root_general_V = json_tokens_getFromObject(tokens, string, token_root_O, "general"); settings_validate(token_root_general_V);
		token_root_general_O = json_tokens_getFromValue(tokens, string, token_root_general_V); settings_validate(token_root_general_O);

		token_root_general_epsilon_V = json_tokens_getFromObject(tokens, string, token_root_general_O, "epsilon"); settings_validate(token_root_general_epsilon_V);
		token_root_general_epsilon_N = json_tokens_getFromValue(tokens, string, token_root_general_epsilon_V); settings_validate(token_root_general_epsilon_N);
		token_root_general_size_V = json_tokens_getFromObject(tokens, string, token_root_general_O, "size"); settings_validate(token_root_general_size_V);
		token_root_general_size_O = json_tokens_getFromValue(tokens, string, token_root_general_size_V); settings_validate(token_root_general_size_O);
		token_root_general_size_hopSize_V = json_tokens_getFromObject(tokens, string, token_root_general_size_O, "hopSize"); settings_validate(token_root_general_size_hopSize_V);
		token_root_general_size_hopSize_N = json_tokens_getFromValue(tokens, string, token_root_general_size_hopSize_V); settings_validate(token_root_general_size_hopSize_N);
		token_root_general_size_frameSize_V = json_tokens_getFromObject(tokens, string, token_root_general_size_O, "frameSize"); settings_validate(token_root_general_size_frameSize_V);
		token_root_general_size_frameSize_N = json_tokens_getFromValue(tokens, string, token_root_general_size_frameSize_V); settings_validate(token_root_general_size_frameSize_N);
		token_root_general_samplerate_V = json_tokens_getFromObject(tokens, string, token_root_general_O, "samplerate"); settings_validate(token_root_general_samplerate_V);
		token_root_general_samplerate_O = json_tokens_getFromValue(tokens, string, token_root_general_samplerate_V); settings_validate(token_root_general_samplerate_O);
		token_root_general_samplerate_mu_V = json_tokens_getFromObject(tokens, string, token_root_general_samplerate_O, "mu"); settings_validate(token_root_general_samplerate_mu_V);
		token_root_general_samplerate_mu_N = json_tokens_getFromValue(tokens, string, token_root_general_samplerate_mu_V); settings_validate(token_root_general_samplerate_mu_N);
		token_root_general_samplerate_sigma2_V = json_tokens_getFromObject(tokens, string, token_root_general_samplerate_O, "sigma2"); settings_validate(token_root_general_samplerate_sigma2_V);
		token_root_general_samplerate_sigma2_N = json_tokens_getFromValue(tokens, string, token_root_general_samplerate_sigma2_V); settings_validate(token_root_general_samplerate_sigma2_N);
		token_root_general_speedofsound_V = json_tokens_getFromObject(tokens, string, token_root_general_O, "speedofsound"); settings_validate(token_root_general_speedofsound_V);
		token_root_general_speedofsound_O = json_tokens_getFromValue(tokens, string, token_root_general_speedofsound_V); settings_validate(token_root_general_speedofsound_O);
		token_root_general_speedofsound_mu_V = json_tokens_getFromObject(tokens, string, token_root_general_speedofsound_O, "mu"); settings_validate(token_root_general_speedofsound_mu_V);
		token_root_general_speedofsound_mu_N = json_tokens_getFromValue(tokens, string, token_root_general_speedofsound_mu_V); settings_validate(token_root_general_speedofsound_mu_N);
		token_root_general_speedofsound_sigma2_V = json_tokens_getFromObject(tokens, string, token_root_general_speedofsound_O, "sigma2"); settings_validate(token_root_general_speedofsound_sigma2_V);
		token_root_general_speedofsound_sigma2_N = json_tokens_getFromValue(tokens, string, token_root_general_speedofsound_sigma2_V); settings_validate(token_root_general_speedofsound_sigma2_N);

		token_root_general_mics_V = json_tokens_getFromObject(tokens, string, token_root_general_O, "mics"); settings_validate(token_root_general_mics_V);
		token_root_general_mics_A = json_tokens_getFromValue(tokens, string, token_root_general_mics_V); settings_validate(token_root_general_mics_A);
		
		nMics = json_tokens_count(tokens, string, token_root_general_mics_A);

		for (iMic = 0; iMic < nMics; iMic++) {

			token_root_general_mics_e_V[iMic] = json_tokens_getFromArray(tokens, string, token_root_general_mics_A, iMic); settings_validate(token_root_general_mics_e_V[iMic]);
			token_root_general_mics_e_O[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_V[iMic]); settings_validate(token_root_general_mics_e_O[iMic]);

			token_root_general_mics_e_mus_V[iMic] = json_tokens_getFromObject(tokens, string, token_root_general_mics_e_O[iMic], "mu"); settings_validate(token_root_general_mics_e_mus_V[iMic]);
			token_root_general_mics_e_mus_A[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_mus_V[iMic]); settings_validate(token_root_general_mics_e_mus_A[iMic]);

			token_root_general_mics_e_mus_0_V[iMic] = json_tokens_getFromArray(tokens, string, token_root_general_mics_e_mus_A[iMic], 0); settings_validate(token_root_general_mics_e_mus_0_V[iMic]);
			token_root_general_mics_e_mus_0_N[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_mus_0_V[iMic]); settings_validate(token_root_general_mics_e_mus_0_N[iMic]);
			token_root_general_mics_e_mus_1_V[iMic] = json_tokens_getFromArray(tokens, string, token_root_general_mics_e_mus_A[iMic], 1); settings_validate(token_root_general_mics_e_mus_1_V[iMic]);
			token_root_general_mics_e_mus_1_N[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_mus_1_V[iMic]); settings_validate(token_root_general_mics_e_mus_1_N[iMic]);
			token_root_general_mics_e_mus_2_V[iMic] = json_tokens_getFromArray(tokens, string, token_root_general_mics_e_mus_A[iMic], 2); settings_validate(token_root_general_mics_e_mus_2_V[iMic]);
			token_root_general_mics_e_mus_2_N[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_mus_2_V[iMic]); settings_validate(token_root_general_mics_e_mus_2_N[iMic]);

			token_root_general_mics_e_sigma2s_V[iMic] = json_tokens_getFromObject(tokens, string, token_root_general_mics_e_O[iMic], "sigma2"); settings_validate(token_root_general_mics_e_sigma2s_V[iMic]);
			token_root_general_mics_e_sigma2s_A[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_sigma2s_V[iMic]); settings_validate(token_root_general_mics_e_sigma2s_A[iMic]);

			token_root_general_mics_e_sigma2s_0_V[iMic] = json_tokens_getFromArray(tokens, string, token_root_general_mics_e_sigma2s_A[iMic], 0); settings_validate(token_root_general_mics_e_sigma2s_0_V[iMic]);
			token_root_general_mics_e_sigma2s_0_N[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_sigma2s_0_V[iMic]); settings_validate(token_root_general_mics_e_sigma2s_0_N[iMic]);
			token_root_general_mics_e_sigma2s_1_V[iMic] = json_tokens_getFromArray(tokens, string, token_root_general_mics_e_sigma2s_A[iMic], 1); settings_validate(token_root_general_mics_e_sigma2s_1_V[iMic]);
			token_root_general_mics_e_sigma2s_1_N[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_sigma2s_1_V[iMic]); settings_validate(token_root_general_mics_e_sigma2s_1_N[iMic]);
			token_root_general_mics_e_sigma2s_2_V[iMic] = json_tokens_getFromArray(tokens, string, token_root_general_mics_e_sigma2s_A[iMic], 2); settings_validate(token_root_general_mics_e_sigma2s_2_V[iMic]);
			token_root_general_mics_e_sigma2s_2_N[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_sigma2s_2_V[iMic]); settings_validate(token_root_general_mics_e_sigma2s_2_N[iMic]);
			token_root_general_mics_e_sigma2s_3_V[iMic] = json_tokens_getFromArray(tokens, string, token_root_general_mics_e_sigma2s_A[iMic], 3); settings_validate(token_root_general_mics_e_sigma2s_3_V[iMic]);
			token_root_general_mics_e_sigma2s_3_N[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_sigma2s_3_V[iMic]); settings_validate(token_root_general_mics_e_sigma2s_3_N[iMic]);
			token_root_general_mics_e_sigma2s_4_V[iMic] = json_tokens_getFromArray(tokens, string, token_root_general_mics_e_sigma2s_A[iMic], 4); settings_validate(token_root_general_mics_e_sigma2s_4_V[iMic]);
			token_root_general_mics_e_sigma2s_4_N[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_sigma2s_4_V[iMic]); settings_validate(token_root_general_mics_e_sigma2s_4_N[iMic]);
			token_root_general_mics_e_sigma2s_5_V[iMic] = json_tokens_getFromArray(tokens, string, token_root_general_mics_e_sigma2s_A[iMic], 5); settings_validate(token_root_general_mics_e_sigma2s_5_V[iMic]);
			token_root_general_mics_e_sigma2s_5_N[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_sigma2s_5_V[iMic]); settings_validate(token_root_general_mics_e_sigma2s_5_N[iMic]);
			token_root_general_mics_e_sigma2s_6_V[iMic] = json_tokens_getFromArray(tokens, string, token_root_general_mics_e_sigma2s_A[iMic], 6); settings_validate(token_root_general_mics_e_sigma2s_6_V[iMic]);
			token_root_general_mics_e_sigma2s_6_N[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_sigma2s_6_V[iMic]); settings_validate(token_root_general_mics_e_sigma2s_6_N[iMic]);
			token_root_general_mics_e_sigma2s_7_V[iMic] = json_tokens_getFromArray(tokens, string, token_root_general_mics_e_sigma2s_A[iMic], 7); settings_validate(token_root_general_mics_e_sigma2s_7_V[iMic]);
			token_root_general_mics_e_sigma2s_7_N[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_sigma2s_7_V[iMic]); settings_validate(token_root_general_mics_e_sigma2s_7_N[iMic]);
			token_root_general_mics_e_sigma2s_8_V[iMic] = json_tokens_getFromArray(tokens, string, token_root_general_mics_e_sigma2s_A[iMic], 8); settings_validate(token_root_general_mics_e_sigma2s_8_V[iMic]);
			token_root_general_mics_e_sigma2s_8_N[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_sigma2s_8_V[iMic]); settings_validate(token_root_general_mics_e_sigma2s_8_N[iMic]);

			token_root_general_mics_e_directions_V[iMic] = json_tokens_getFromObject(tokens, string, token_root_general_mics_e_O[iMic], "direction"); settings_validate(token_root_general_mics_e_directions_V[iMic]);
			token_root_general_mics_e_directions_A[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_directions_V[iMic]); settings_validate(token_root_general_mics_e_directions_A[iMic]);

			token_root_general_mics_e_directions_0_V[iMic] = json_tokens_getFromArray(tokens, string, token_root_general_mics_e_directions_A[iMic], 0); settings_validate(token_root_general_mics_e_directions_0_V[iMic]);
			token_root_general_mics_e_directions_0_N[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_directions_0_V[iMic]); settings_validate(token_root_general_mics_e_directions_0_N[iMic]);
			token_root_general_mics_e_directions_1_V[iMic] = json_tokens_getFromArray(tokens, string, token_root_general_mics_e_directions_A[iMic], 1); settings_validate(token_root_general_mics_e_directions_1_V[iMic]);
			token_root_general_mics_e_directions_1_N[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_directions_1_V[iMic]); settings_validate(token_root_general_mics_e_directions_1_N[iMic]);
			token_root_general_mics_e_directions_2_V[iMic] = json_tokens_getFromArray(tokens, string, token_root_general_mics_e_directions_A[iMic], 2); settings_validate(token_root_general_mics_e_directions_2_V[iMic]);
			token_root_general_mics_e_directions_2_N[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_directions_2_V[iMic]); settings_validate(token_root_general_mics_e_directions_2_N[iMic]);

			token_root_general_mics_e_angles_V[iMic] = json_tokens_getFromObject(tokens, string, token_root_general_mics_e_O[iMic], "angle"); settings_validate(token_root_general_mics_e_angles_V[iMic]);
			token_root_general_mics_e_angles_A[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_angles_V[iMic]); settings_validate(token_root_general_mics_e_angles_A[iMic]);

			token_root_general_mics_e_angles_0_V[iMic] = json_tokens_getFromArray(tokens, string, token_root_general_mics_e_angles_A[iMic], 0); settings_validate(token_root_general_mics_e_angles_0_V[iMic]);
			token_root_general_mics_e_angles_0_N[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_angles_0_V[iMic]); settings_validate(token_root_general_mics_e_angles_0_N[iMic]);
			token_root_general_mics_e_angles_1_V[iMic] = json_tokens_getFromArray(tokens, string, token_root_general_mics_e_angles_A[iMic], 1); settings_validate(token_root_general_mics_e_angles_1_V[iMic]);
			token_root_general_mics_e_angles_1_N[iMic] = json_tokens_getFromValue(tokens, string, token_root_general_mics_e_angles_1_V[iMic]); settings_validate(token_root_general_mics_e_angles_1_N[iMic]);

		}

		token_root_general_spatialfilters_V = json_tokens_getFromObject(tokens, string, token_root_general_O, "spatialfilters"); settings_validate(token_root_general_spatialfilters_V);
		token_root_general_spatialfilters_A = json_tokens_getFromValue(tokens, string, token_root_general_spatialfilters_V); settings_validate(token_root_general_spatialfilters_A);
		
		nSpatialFilters = json_tokens_count(tokens, string, token_root_general_spatialfilters_A);

		for (iSpatialFilter = 0; iSpatialFilter < nSpatialFilters; iSpatialFilter++) {

			token_root_general_spatialfilters_e_V[iSpatialFilter] = json_tokens_getFromArray(tokens, string, token_root_general_spatialfilters_A, iSpatialFilter); settings_validate(token_root_general_spatialfilters_e_V[iSpatialFilter]);
			token_root_general_spatialfilters_e_O[iSpatialFilter] = json_tokens_getFromValue(tokens, string, token_root_general_spatialfilters_e_V[iSpatialFilter]); settings_validate(token_root_general_spatialfilters_e_O[iSpatialFilter]);

			token_root_general_spatialfilters_e_directions_V[iSpatialFilter] = json_tokens_getFromObject(tokens, string, token_root_general_spatialfilters_e_O[iSpatialFilter], "directions"); settings_validate(token_root_general_spatialfilters_e_directions_V[iSpatialFilter]);
			token_root_general_spatialfilters_e_directions_A[iSpatialFilter] = json_tokens_getFromValue(tokens, string, token_root_general_spatialfilters_e_directions_V[iSpatialFilter]); settings_validate(token_root_general_spatialfilters_e_directions_A[iSpatialFilter]);

			token_root_general_spatialfilters_e_directions_0_V[iSpatialFilter] = json_tokens_getFromArray(tokens, string, token_root_general_spatialfilters_e_directions_A[iSpatialFilter], 0); settings_validate(token_root_general_spatialfilters_e_directions_0_V[iSpatialFilter]);
			token_root_general_spatialfilters_e_directions_0_N[iSpatialFilter] = json_tokens_getFromValue(tokens, string, token_root_general_spatialfilters_e_directions_0_V[iSpatialFilter]); settings_validate(token_root_general_spatialfilters_e_directions_0_N[iSpatialFilter]);
			token_root_general_spatialfilters_e_directions_1_V[iSpatialFilter] = json_tokens_getFromArray(tokens, string, token_root_general_spatialfilters_e_directions_A[iSpatialFilter], 1); settings_validate(token_root_general_spatialfilters_e_directions_1_V[iSpatialFilter]);
			token_root_general_spatialfilters_e_directions_1_N[iSpatialFilter] = json_tokens_getFromValue(tokens, string, token_root_general_spatialfilters_e_directions_1_V[iSpatialFilter]); settings_validate(token_root_general_spatialfilters_e_directions_1_N[iSpatialFilter]);
			token_root_general_spatialfilters_e_directions_2_V[iSpatialFilter] = json_tokens_getFromArray(tokens, string, token_root_general_spatialfilters_e_directions_A[iSpatialFilter], 2); settings_validate(token_root_general_spatialfilters_e_directions_2_V[iSpatialFilter]);
			token_root_general_spatialfilters_e_directions_2_N[iSpatialFilter] = json_tokens_getFromValue(tokens, string, token_root_general_spatialfilters_e_directions_2_V[iSpatialFilter]); settings_validate(token_root_general_spatialfilters_e_directions_2_N[iSpatialFilter]);

			token_root_general_spatialfilters_e_angles_V[iSpatialFilter] = json_tokens_getFromObject(tokens, string, token_root_general_spatialfilters_e_O[iSpatialFilter], "angles"); settings_validate(token_root_general_spatialfilters_e_angles_V[iSpatialFilter]);
			token_root_general_spatialfilters_e_angles_A[iSpatialFilter] = json_tokens_getFromValue(tokens, string, token_root_general_spatialfilters_e_angles_V[iSpatialFilter]); settings_validate(token_root_general_spatialfilters_e_angles_A[iSpatialFilter]);

			token_root_general_spatialfilters_e_angles_0_V[iSpatialFilter] = json_tokens_getFromArray(tokens, string, token_root_general_spatialfilters_e_angles_A[iSpatialFilter], 0); settings_validate(token_root_general_spatialfilters_e_angles_0_V[iSpatialFilter]);
			token_root_general_spatialfilters_e_angles_0_N[iSpatialFilter] = json_tokens_getFromValue(tokens, string, token_root_general_spatialfilters_e_angles_0_V[iSpatialFilter]); settings_validate(token_root_general_spatialfilters_e_angles_0_N[iSpatialFilter]);
			token_root_general_spatialfilters_e_angles_1_V[iSpatialFilter] = json_tokens_getFromArray(tokens, string, token_root_general_spatialfilters_e_angles_A[iSpatialFilter], 1); settings_validate(token_root_general_spatialfilters_e_angles_1_V[iSpatialFilter]);
			token_root_general_spatialfilters_e_angles_1_N[iSpatialFilter] = json_tokens_getFromValue(tokens, string, token_root_general_spatialfilters_e_angles_1_V[iSpatialFilter]); settings_validate(token_root_general_spatialfilters_e_angles_1_N[iSpatialFilter]);

		}

		token_root_general_nthetas_V = json_tokens_getFromObject(tokens, string, token_root_general_O, "nThetas"); settings_validate(token_root_general_nthetas_V);
		token_root_general_nthetas_N = json_tokens_getFromValue(tokens, string, token_root_general_nthetas_V); settings_validate(token_root_general_nthetas_N);
		token_root_general_gainmin_V = json_tokens_getFromObject(tokens, string, token_root_general_O, "gainMin"); settings_validate(token_root_general_gainmin_V);
		token_root_general_gainmin_N = json_tokens_getFromValue(tokens, string, token_root_general_gainmin_V); settings_validate(token_root_general_gainmin_N);

		token_root_sne_V = json_tokens_getFromObject(tokens, string, token_root_O, "sne"); settings_validate(token_root_sne_V);
		token_root_sne_O = json_tokens_getFromValue(tokens, string, token_root_sne_V); settings_validate(token_root_sne_O);

		token_root_sne_b_V = json_tokens_getFromObject(tokens, string, token_root_sne_O, "b"); settings_validate(token_root_sne_b_V);
		token_root_sne_b_N = json_tokens_getFromValue(tokens, string, token_root_sne_b_V); settings_validate(token_root_sne_b_N);
		token_root_sne_alphaS_V = json_tokens_getFromObject(tokens, string, token_root_sne_O, "alphaS"); settings_validate(token_root_sne_alphaS_V);
		token_root_sne_alphaS_N = json_tokens_getFromValue(tokens, string, token_root_sne_alphaS_V); settings_validate(token_root_sne_alphaS_N);
		token_root_sne_L_V = json_tokens_getFromObject(tokens, string, token_root_sne_O, "L"); settings_validate(token_root_sne_L_V);
		token_root_sne_L_N = json_tokens_getFromValue(tokens, string, token_root_sne_L_V); settings_validate(token_root_sne_L_N);
		token_root_sne_delta_V = json_tokens_getFromObject(tokens, string, token_root_sne_O, "delta"); settings_validate(token_root_sne_delta_V);
		token_root_sne_delta_N = json_tokens_getFromValue(tokens, string, token_root_sne_delta_V); settings_validate(token_root_sne_delta_N);
		token_root_sne_alphaD_V = json_tokens_getFromObject(tokens, string, token_root_sne_O, "alphaD"); settings_validate(token_root_sne_alphaD_V);
		token_root_sne_alphaD_N = json_tokens_getFromValue(tokens, string, token_root_sne_alphaD_V); settings_validate(token_root_sne_alphaD_N);

		token_root_ssl_V = json_tokens_getFromObject(tokens, string, token_root_O, "ssl"); settings_validate(token_root_ssl_V);
		token_root_ssl_O = json_tokens_getFromValue(tokens, string, token_root_ssl_V); settings_validate(token_root_ssl_O);

		token_root_ssl_nPots_V = json_tokens_getFromObject(tokens, string, token_root_ssl_O, "nPots"); settings_validate(token_root_ssl_nPots_V);
		token_root_ssl_nPots_N = json_tokens_getFromValue(tokens, string, token_root_ssl_nPots_V); settings_validate(token_root_ssl_nPots_N);
		token_root_ssl_nMatches_V = json_tokens_getFromObject(tokens, string, token_root_ssl_O, "nMatches"); settings_validate(token_root_ssl_nMatches_V);
		token_root_ssl_nMatches_N = json_tokens_getFromValue(tokens, string, token_root_ssl_nMatches_V); settings_validate(token_root_ssl_nMatches_N);
		token_root_ssl_probMin_V = json_tokens_getFromObject(tokens, string, token_root_ssl_O, "probMin"); settings_validate(token_root_ssl_probMin_V);
		token_root_ssl_probMin_N = json_tokens_getFromValue(tokens, string, token_root_ssl_probMin_V); settings_validate(token_root_ssl_probMin_N);
		token_root_ssl_nRefinedLevels_V = json_tokens_getFromObject(tokens, string, token_root_ssl_O, "nRefinedLevels"); settings_validate(token_root_ssl_nRefinedLevels_V);
		token_root_ssl_nRefinedLevels_N = json_tokens_getFromValue(tokens, string, token_root_ssl_nRefinedLevels_V); settings_validate(token_root_ssl_nRefinedLevels_N);
		token_root_ssl_interpRate_V = json_tokens_getFromObject(tokens, string, token_root_ssl_O, "interpRate"); settings_validate(token_root_ssl_interpRate_V);
		token_root_ssl_interpRate_N = json_tokens_getFromValue(tokens, string, token_root_ssl_interpRate_V); settings_validate(token_root_ssl_interpRate_N);

		token_root_ssl_scans_V = json_tokens_getFromObject(tokens, string, token_root_ssl_O, "scans"); settings_validate(token_root_ssl_scans_V);
		token_root_ssl_scans_A = json_tokens_getFromValue(tokens, string, token_root_ssl_scans_V); settings_validate(token_root_ssl_scans_A);

		nScans = json_tokens_count(tokens, string, token_root_ssl_scans_A);

		for (iScan = 0; iScan < nScans; iScan++) {

			token_root_ssl_scans_e_V[iScan] = json_tokens_getFromArray(tokens, string, token_root_ssl_scans_A, iScan); settings_validate(token_root_ssl_scans_e_V[iScan]);
			token_root_ssl_scans_e_O[iScan] = json_tokens_getFromValue(tokens, string, token_root_ssl_scans_e_V[iScan]); settings_validate(token_root_ssl_scans_e_O[iScan]);

			token_root_ssl_scans_e_level_V[iScan] = json_tokens_getFromObject(tokens, string, token_root_ssl_scans_e_O[iScan], "level"); settings_validate(token_root_ssl_scans_e_level_V[iScan]);
			token_root_ssl_scans_e_level_N[iScan] = json_tokens_getFromValue(tokens, string, token_root_ssl_scans_e_level_V[iScan]); settings_validate(token_root_ssl_scans_e_level_N[iScan]);
			token_root_ssl_scans_e_delta_V[iScan] = json_tokens_getFromObject(tokens, string, token_root_ssl_scans_e_O[iScan], "delta"); settings_validate(token_root_ssl_scans_e_delta_V[iScan]);
			token_root_ssl_scans_e_delta_N[iScan] = json_tokens_getFromValue(tokens, string, token_root_ssl_scans_e_delta_V[iScan]); settings_validate(token_root_ssl_scans_e_delta_N[iScan]);

		}

		token_root_sst_V = json_tokens_getFromObject(tokens, string, token_root_O, "sst"); settings_validate(token_root_sst_V);
		token_root_sst_O = json_tokens_getFromValue(tokens, string, token_root_sst_V); settings_validate(token_root_sst_O);

		token_root_sst_mode_V = json_tokens_getFromObject(tokens, string, token_root_sst_O, "mode"); settings_validate(token_root_sst_mode_V);
		token_root_sst_mode_S = json_tokens_getFromValue(tokens, string, token_root_sst_mode_V); settings_validate(token_root_sst_mode_S);
		token_root_sst_add_V = json_tokens_getFromObject(tokens, string, token_root_sst_O, "add"); settings_validate(token_root_sst_add_V);
		token_root_sst_add_S = json_tokens_getFromValue(tokens, string, token_root_sst_add_V); settings_validate(token_root_sst_add_S);

		token_root_sst_energy_V = json_tokens_getFromObject(tokens, string, token_root_sst_O, "energy"); settings_validate(token_root_sst_energy_V);
		token_root_sst_energy_O = json_tokens_getFromValue(tokens, string, token_root_sst_energy_V); settings_validate(token_root_sst_energy_O);
		token_root_sst_energy_active_V = json_tokens_getFromObject(tokens, string, token_root_sst_energy_O, "active"); settings_validate(token_root_sst_energy_active_V);
		token_root_sst_energy_active_A = json_tokens_getFromValue(tokens, string, token_root_sst_energy_active_V); settings_validate(token_root_sst_energy_active_A);
		token_root_sst_energy_inactive_V = json_tokens_getFromObject(tokens, string, token_root_sst_energy_O, "inactive"); settings_validate(token_root_sst_energy_inactive_V);
		token_root_sst_energy_inactive_A = json_tokens_getFromValue(tokens, string, token_root_sst_energy_inactive_V); settings_validate(token_root_sst_energy_inactive_A);

		nGaussiansActive = json_tokens_count(tokens, string, token_root_sst_energy_active_A);

		for (iGaussianActive = 0; iGaussianActive < nGaussiansActive; iGaussianActive++) {

			token_root_sst_energy_active_e_V[iGaussianActive] = json_tokens_getFromArray(tokens, string, token_root_sst_energy_active_A, iGaussianActive); settings_validate(token_root_sst_energy_active_e_V[iGaussianActive]);
			token_root_sst_energy_active_e_O[iGaussianActive] = json_tokens_getFromValue(tokens, string, token_root_sst_energy_active_e_V[iGaussianActive]); settings_validate(token_root_sst_energy_active_e_O[iGaussianActive]);
			token_root_sst_energy_active_e_weight_V[iGaussianActive] = json_tokens_getFromObject(tokens, string, token_root_sst_energy_active_e_O[iGaussianActive], "weight"); settings_validate(token_root_sst_energy_active_e_weight_V[iGaussianActive]);
			token_root_sst_energy_active_e_weight_N[iGaussianActive] = json_tokens_getFromValue(tokens, string, token_root_sst_energy_active_e_weight_V[iGaussianActive]); settings_validate(token_root_sst_energy_active_e_weight_N[iGaussianActive]);
			token_root_sst_energy_active_e_mu_V[iGaussianActive] = json_tokens_getFromObject(tokens, string, token_root_sst_energy_active_e_O[iGaussianActive], "mu"); settings_validate(token_root_sst_energy_active_e_mu_V[iGaussianActive]);
			token_root_sst_energy_active_e_mu_N[iGaussianActive] = json_tokens_getFromValue(tokens, string, token_root_sst_energy_active_e_mu_V[iGaussianActive]); settings_validate(token_root_sst_energy_active_e_mu_N[iGaussianActive]);
			token_root_sst_energy_active_e_sigma2_V[iGaussianActive] = json_tokens_getFromObject(tokens, string, token_root_sst_energy_active_e_O[iGaussianActive], "sigma2"); settings_validate(token_root_sst_energy_active_e_sigma2_V[iGaussianActive]);
			token_root_sst_energy_active_e_sigma2_N[iGaussianActive] = json_tokens_getFromValue(tokens, string, token_root_sst_energy_active_e_sigma2_V[iGaussianActive]); settings_validate(token_root_sst_energy_active_e_sigma2_N[iGaussianActive]);

		}

		nGaussiansInactive = json_tokens_count(tokens, string, token_root_sst_energy_inactive_A);

		for (iGaussianInactive = 0; iGaussianInactive < nGaussiansInactive; iGaussianInactive++) {

			token_root_sst_energy_inactive_e_V[iGaussianInactive] = json_tokens_getFromArray(tokens, string, token_root_sst_energy_inactive_A, iGaussianInactive); settings_validate(token_root_sst_energy_inactive_e_V[iGaussianInactive]);
			token_root_sst_energy_inactive_e_O[iGaussianInactive] = json_tokens_getFromValue(tokens, string, token_root_sst_energy_inactive_e_V[iGaussianInactive]); settings_validate(token_root_sst_energy_inactive_e_O[iGaussianInactive]);
			token_root_sst_energy_inactive_e_weight_V[iGaussianInactive] = json_tokens_getFromObject(tokens, string, token_root_sst_energy_inactive_e_O[iGaussianInactive], "weight"); settings_validate(token_root_sst_energy_inactive_e_weight_V[iGaussianInactive]);
			token_root_sst_energy_inactive_e_weight_N[iGaussianInactive] = json_tokens_getFromValue(tokens, string, token_root_sst_energy_inactive_e_weight_V[iGaussianInactive]); settings_validate(token_root_sst_energy_inactive_e_weight_N[iGaussianInactive]);
			token_root_sst_energy_inactive_e_mu_V[iGaussianInactive] = json_tokens_getFromObject(tokens, string, token_root_sst_energy_inactive_e_O[iGaussianInactive], "mu"); settings_validate(token_root_sst_energy_inactive_e_mu_V[iGaussianInactive]);
			token_root_sst_energy_inactive_e_mu_N[iGaussianInactive] = json_tokens_getFromValue(tokens, string, token_root_sst_energy_inactive_e_mu_V[iGaussianInactive]); settings_validate(token_root_sst_energy_inactive_e_mu_N[iGaussianInactive]);
			token_root_sst_energy_inactive_e_sigma2_V[iGaussianInactive] = json_tokens_getFromObject(tokens, string, token_root_sst_energy_inactive_e_O[iGaussianInactive], "sigma2"); settings_validate(token_root_sst_energy_inactive_e_sigma2_V[iGaussianInactive]);
			token_root_sst_energy_inactive_e_sigma2_N[iGaussianInactive] = json_tokens_getFromValue(tokens, string, token_root_sst_energy_inactive_e_sigma2_V[iGaussianInactive]); settings_validate(token_root_sst_energy_inactive_e_sigma2_N[iGaussianInactive]);

		}

		token_root_sst_sigmaR2_V = json_tokens_getFromObject(tokens, string, token_root_sst_O, "sigmaR2"); settings_validate(token_root_sst_sigmaR2_V);
		token_root_sst_sigmaR2_O = json_tokens_getFromValue(tokens, string, token_root_sst_sigmaR2_V); settings_validate(token_root_sst_sigmaR2_O);
		token_root_sst_sigmaR2_prob_V = json_tokens_getFromObject(tokens, string, token_root_sst_sigmaR2_O, "prob"); settings_validate(token_root_sst_sigmaR2_prob_V);
		token_root_sst_sigmaR2_prob_N = json_tokens_getFromValue(tokens, string, token_root_sst_sigmaR2_prob_V); settings_validate(token_root_sst_sigmaR2_prob_N);
		token_root_sst_sigmaR2_active_V = json_tokens_getFromObject(tokens, string, token_root_sst_sigmaR2_O, "active"); settings_validate(token_root_sst_sigmaR2_active_V);
		token_root_sst_sigmaR2_active_N = json_tokens_getFromValue(tokens, string, token_root_sst_sigmaR2_active_V); settings_validate(token_root_sst_sigmaR2_active_N);
		token_root_sst_sigmaR2_target_V = json_tokens_getFromObject(tokens, string, token_root_sst_sigmaR2_O, "target"); settings_validate(token_root_sst_sigmaR2_target_V);
		token_root_sst_sigmaR2_target_N = json_tokens_getFromValue(tokens, string, token_root_sst_sigmaR2_target_V); settings_validate(token_root_sst_sigmaR2_target_N);

		token_root_sst_P_V = json_tokens_getFromObject(tokens, string, token_root_sst_O, "P"); settings_validate(token_root_sst_P_V);
		token_root_sst_P_O = json_tokens_getFromValue(tokens, string, token_root_sst_P_V); settings_validate(token_root_sst_P_O);
		token_root_sst_P_false_V = json_tokens_getFromObject(tokens, string, token_root_sst_P_O, "false"); settings_validate(token_root_sst_P_false_V);
		token_root_sst_P_false_N = json_tokens_getFromValue(tokens, string, token_root_sst_P_false_V); settings_validate(token_root_sst_P_false_N);
		token_root_sst_P_new_V = json_tokens_getFromObject(tokens, string, token_root_sst_P_O, "new"); settings_validate(token_root_sst_P_new_V);
		token_root_sst_P_new_N = json_tokens_getFromValue(tokens, string, token_root_sst_P_new_V); settings_validate(token_root_sst_P_new_N);
		token_root_sst_P_track_V = json_tokens_getFromObject(tokens, string, token_root_sst_P_O, "track"); settings_validate(token_root_sst_P_track_V);
		token_root_sst_P_track_N = json_tokens_getFromValue(tokens, string, token_root_sst_P_track_V); settings_validate(token_root_sst_P_track_N);

		token_root_sst_levels_V = json_tokens_getFromObject(tokens, string, token_root_sst_O, "levels"); settings_validate(token_root_sst_levels_V);
		token_root_sst_levels_O = json_tokens_getFromValue(tokens, string, token_root_sst_levels_V); settings_validate(token_root_sst_levels_O);
		token_root_sst_levels_new_V = json_tokens_getFromObject(tokens, string, token_root_sst_levels_O, "new"); settings_validate(token_root_sst_levels_new_V);
		token_root_sst_levels_new_O = json_tokens_getFromValue(tokens, string, token_root_sst_levels_new_V); settings_validate(token_root_sst_levels_new_O);
		token_root_sst_levels_new_theta_V = json_tokens_getFromObject(tokens, string, token_root_sst_levels_new_O, "theta"); settings_validate(token_root_sst_levels_new_theta_V);
		token_root_sst_levels_new_theta_N = json_tokens_getFromValue(tokens, string, token_root_sst_levels_new_theta_V); settings_validate(token_root_sst_levels_new_theta_N);
		token_root_sst_levels_prob_V = json_tokens_getFromObject(tokens, string, token_root_sst_levels_O, "prob"); settings_validate(token_root_sst_levels_prob_V);
		token_root_sst_levels_prob_O = json_tokens_getFromValue(tokens, string, token_root_sst_levels_prob_V); settings_validate(token_root_sst_levels_prob_O);
		token_root_sst_levels_prob_theta_V = json_tokens_getFromObject(tokens, string, token_root_sst_levels_prob_O, "theta"); settings_validate(token_root_sst_levels_prob_theta_V);
		token_root_sst_levels_prob_theta_N = json_tokens_getFromValue(tokens, string, token_root_sst_levels_prob_theta_V); settings_validate(token_root_sst_levels_prob_theta_N);
		token_root_sst_levels_prob_N_V = json_tokens_getFromObject(tokens, string, token_root_sst_levels_prob_O, "N"); settings_validate(token_root_sst_levels_prob_N_V);
		token_root_sst_levels_prob_N_N = json_tokens_getFromValue(tokens, string, token_root_sst_levels_prob_N_V); settings_validate(token_root_sst_levels_prob_N_N);
		token_root_sst_levels_inactive_V = json_tokens_getFromObject(tokens, string, token_root_sst_levels_O, "inactive"); settings_validate(token_root_sst_levels_inactive_V);
		token_root_sst_levels_inactive_O = json_tokens_getFromValue(tokens, string, token_root_sst_levels_inactive_V); settings_validate(token_root_sst_levels_inactive_O);
		token_root_sst_levels_inactive_theta_V = json_tokens_getFromObject(tokens, string, token_root_sst_levels_inactive_O, "theta"); settings_validate(token_root_sst_levels_inactive_theta_V);
		token_root_sst_levels_inactive_theta_N = json_tokens_getFromValue(tokens, string, token_root_sst_levels_inactive_theta_V); settings_validate(token_root_sst_levels_inactive_theta_N);
		token_root_sst_levels_inactive_Ns_V = json_tokens_getFromObject(tokens, string, token_root_sst_levels_inactive_O, "N"); settings_validate(token_root_sst_levels_inactive_Ns_V);
		token_root_sst_levels_inactive_Ns_A = json_tokens_getFromValue(tokens, string, token_root_sst_levels_inactive_Ns_V); settings_validate(token_root_sst_levels_inactive_Ns_A);

		nLevels = json_tokens_count(tokens, string, token_root_sst_levels_inactive_Ns_A);

		for (iLevel = 0; iLevel < nLevels; iLevel++) {

			token_root_sst_levels_inactive_Ns_e_V[iLevel] = json_tokens_getFromArray(tokens, string, token_root_sst_levels_inactive_Ns_A, iLevel); settings_validate(token_root_sst_levels_inactive_Ns_e_V[iLevel]);
			token_root_sst_levels_inactive_Ns_e_N[iLevel] = json_tokens_getFromValue(tokens, string, token_root_sst_levels_inactive_Ns_e_V[iLevel]); settings_validate(token_root_sst_levels_inactive_Ns_e_N[iLevel]);

		}

		token_root_sst_kalman_V = json_tokens_getFromObject(tokens, string, token_root_sst_O, "kalman"); settings_validate(token_root_sst_kalman_V);
		token_root_sst_kalman_O = json_tokens_getFromValue(tokens, string, token_root_sst_kalman_V); settings_validate(token_root_sst_kalman_O);
		token_root_sst_kalman_sigmaQ_V = json_tokens_getFromObject(tokens, string, token_root_sst_kalman_O, "sigmaQ"); settings_validate(token_root_sst_kalman_sigmaQ_V);
		token_root_sst_kalman_sigmaQ_N = json_tokens_getFromValue(tokens, string, token_root_sst_kalman_sigmaQ_V); settings_validate(token_root_sst_kalman_sigmaQ_N);

		token_root_sst_particle_V = json_tokens_getFromObject(tokens, string, token_root_sst_O, "particle"); settings_validate(token_root_sst_particle_V);
		token_root_sst_particle_O = json_tokens_getFromValue(tokens, string, token_root_sst_particle_V); settings_validate(token_root_sst_particle_O);
		token_root_sst_particle_nParticles_V = json_tokens_getFromObject(tokens, string, token_root_sst_particle_O, "nParticles"); settings_validate(token_root_sst_particle_nParticles_V);
		token_root_sst_particle_nParticles_N = json_tokens_getFromValue(tokens, string, token_root_sst_particle_nParticles_V); settings_validate(token_root_sst_particle_nParticles_N);

		token_root_sst_particle_stationary_V = json_tokens_getFromObject(tokens, string, token_root_sst_particle_O, "stationary"); settings_validate(token_root_sst_particle_stationary_V);
		token_root_sst_particle_stationary_O = json_tokens_getFromValue(tokens, string, token_root_sst_particle_stationary_V); settings_validate(token_root_sst_particle_stationary_O);
		token_root_sst_particle_stationary_alpha_V = json_tokens_getFromObject(tokens, string, token_root_sst_particle_stationary_O, "alpha"); settings_validate(token_root_sst_particle_stationary_alpha_V);
		token_root_sst_particle_stationary_alpha_N = json_tokens_getFromValue(tokens, string, token_root_sst_particle_stationary_alpha_V); settings_validate(token_root_sst_particle_stationary_alpha_N);
		token_root_sst_particle_stationary_beta_V = json_tokens_getFromObject(tokens, string, token_root_sst_particle_stationary_O, "beta"); settings_validate(token_root_sst_particle_stationary_beta_V);
		token_root_sst_particle_stationary_beta_N = json_tokens_getFromValue(tokens, string, token_root_sst_particle_stationary_beta_V); settings_validate(token_root_sst_particle_stationary_beta_N);
		token_root_sst_particle_stationary_ratio_V = json_tokens_getFromObject(tokens, string, token_root_sst_particle_stationary_O, "ratio"); settings_validate(token_root_sst_particle_stationary_ratio_V);
		token_root_sst_particle_stationary_ratio_N = json_tokens_getFromValue(tokens, string, token_root_sst_particle_stationary_ratio_V); settings_validate(token_root_sst_particle_stationary_ratio_N);
		
		token_root_sst_particle_velocity_V = json_tokens_getFromObject(tokens, string, token_root_sst_particle_O, "velocity"); settings_validate(token_root_sst_particle_velocity_V);
		token_root_sst_particle_velocity_O = json_tokens_getFromValue(tokens, string, token_root_sst_particle_velocity_V); settings_validate(token_root_sst_particle_velocity_O);
		token_root_sst_particle_velocity_alpha_V = json_tokens_getFromObject(tokens, string, token_root_sst_particle_velocity_O, "alpha"); settings_validate(token_root_sst_particle_velocity_alpha_V);
		token_root_sst_particle_velocity_alpha_N = json_tokens_getFromValue(tokens, string, token_root_sst_particle_velocity_alpha_V); settings_validate(token_root_sst_particle_velocity_alpha_N);
		token_root_sst_particle_velocity_beta_V = json_tokens_getFromObject(tokens, string, token_root_sst_particle_velocity_O, "beta"); settings_validate(token_root_sst_particle_velocity_beta_V);
		token_root_sst_particle_velocity_beta_N = json_tokens_getFromValue(tokens, string, token_root_sst_particle_velocity_beta_V); settings_validate(token_root_sst_particle_velocity_beta_N);
		token_root_sst_particle_velocity_ratio_V = json_tokens_getFromObject(tokens, string, token_root_sst_particle_velocity_O, "ratio"); settings_validate(token_root_sst_particle_velocity_ratio_V);
		token_root_sst_particle_velocity_ratio_N = json_tokens_getFromValue(tokens, string, token_root_sst_particle_velocity_ratio_V); settings_validate(token_root_sst_particle_velocity_ratio_N);
		
		token_root_sst_particle_acceleration_V = json_tokens_getFromObject(tokens, string, token_root_sst_particle_O, "acceleration"); settings_validate(token_root_sst_particle_acceleration_V);
		token_root_sst_particle_acceleration_O = json_tokens_getFromValue(tokens, string, token_root_sst_particle_acceleration_V); settings_validate(token_root_sst_particle_acceleration_O);
		token_root_sst_particle_acceleration_alpha_V = json_tokens_getFromObject(tokens, string, token_root_sst_particle_acceleration_O, "alpha"); settings_validate(token_root_sst_particle_acceleration_alpha_V);
		token_root_sst_particle_acceleration_alpha_N = json_tokens_getFromValue(tokens, string, token_root_sst_particle_acceleration_alpha_V); settings_validate(token_root_sst_particle_acceleration_alpha_N);
		token_root_sst_particle_acceleration_beta_V = json_tokens_getFromObject(tokens, string, token_root_sst_particle_acceleration_O, "beta"); settings_validate(token_root_sst_particle_acceleration_beta_V);
		token_root_sst_particle_acceleration_beta_N = json_tokens_getFromValue(tokens, string, token_root_sst_particle_acceleration_beta_V); settings_validate(token_root_sst_particle_acceleration_beta_N);
		token_root_sst_particle_acceleration_ratio_V = json_tokens_getFromObject(tokens, string, token_root_sst_particle_acceleration_O, "ratio"); settings_validate(token_root_sst_particle_acceleration_ratio_V);
		token_root_sst_particle_acceleration_ratio_N = json_tokens_getFromValue(tokens, string, token_root_sst_particle_acceleration_ratio_V); settings_validate(token_root_sst_particle_acceleration_ratio_N);
		
		token_root_sst_particle_Nmin_V = json_tokens_getFromObject(tokens, string, token_root_sst_particle_O, "Nmin"); settings_validate(token_root_sst_particle_Nmin_V);
		token_root_sst_particle_Nmin_N = json_tokens_getFromValue(tokens, string, token_root_sst_particle_Nmin_V); settings_validate(token_root_sst_particle_Nmin_N);

		token_root_sss_V = json_tokens_getFromObject(tokens, string, token_root_O, "sss"); settings_validate(token_root_sss_V);
		token_root_sss_O = json_tokens_getFromValue(tokens, string, token_root_sss_V); settings_validate(token_root_sss_O);

		token_root_sss_offset_V = json_tokens_getFromObject(tokens, string, token_root_sss_O, "offset"); settings_validate(token_root_sss_offset_V);
		token_root_sss_offset_N = json_tokens_getFromValue(tokens, string, token_root_sss_offset_V); settings_validate(token_root_sss_offset_N);

		token_root_sss_separation_V = json_tokens_getFromObject(tokens, string, token_root_sss_O, "separation"); settings_validate(token_root_sss_separation_V);
		token_root_sss_separation_O = json_tokens_getFromValue(tokens, string, token_root_sss_separation_V); settings_validate(token_root_sss_separation_O);

		token_root_sss_separation_mode_V = json_tokens_getFromObject(tokens, string, token_root_sss_separation_O, "mode"); settings_validate(token_root_sss_separation_mode_V);
		token_root_sss_separation_mode_S = json_tokens_getFromValue(tokens, string, token_root_sss_separation_mode_V); settings_validate(token_root_sss_separation_mode_S);
		token_root_sss_separation_techniques_V = json_tokens_getFromObject(tokens, string, token_root_sss_separation_O, "techniques"); settings_validate(token_root_sss_separation_techniques_V);
		token_root_sss_separation_techniques_O = json_tokens_getFromValue(tokens, string, token_root_sss_separation_techniques_V); settings_validate(token_root_sss_separation_techniques_O);
		token_root_sss_separation_techniques_dds_V = json_tokens_getFromObject(tokens, string, token_root_sss_separation_techniques_O, "dds"); settings_validate(token_root_sss_separation_techniques_dds_V);
		token_root_sss_separation_techniques_dds_O = json_tokens_getFromValue(tokens, string, token_root_sss_separation_techniques_dds_V); settings_validate(token_root_sss_separation_techniques_dds_O);
		token_root_sss_separation_techniques_dgss_V = json_tokens_getFromObject(tokens, string, token_root_sss_separation_techniques_O, "dgss"); settings_validate(token_root_sss_separation_techniques_dgss_V);
		token_root_sss_separation_techniques_dgss_O = json_tokens_getFromValue(tokens, string, token_root_sss_separation_techniques_dgss_V); settings_validate(token_root_sss_separation_techniques_dgss_O);
		token_root_sss_separation_techniques_dgss_mu_V = json_tokens_getFromObject(tokens, string, token_root_sss_separation_techniques_dgss_O, "mu"); settings_validate(token_root_sss_separation_techniques_dgss_mu_V);
		token_root_sss_separation_techniques_dgss_mu_N = json_tokens_getFromValue(tokens, string, token_root_sss_separation_techniques_dgss_mu_V); settings_validate(token_root_sss_separation_techniques_dgss_mu_N);
		token_root_sss_separation_techniques_dgss_lambda_V = json_tokens_getFromObject(tokens, string, token_root_sss_separation_techniques_dgss_O, "lambda"); settings_validate(token_root_sss_separation_techniques_dgss_lambda_V);
		token_root_sss_separation_techniques_dgss_lambda_N = json_tokens_getFromValue(tokens, string, token_root_sss_separation_techniques_dgss_lambda_V); settings_validate(token_root_sss_separation_techniques_dgss_lambda_N);
		token_root_sss_separation_techniques_dmvdr_V = json_tokens_getFromObject(tokens, string, token_root_sss_separation_techniques_O, "dmvdr"); settings_validate(token_root_sss_separation_techniques_dmvdr_V);
		token_root_sss_separation_techniques_dmvdr_O = json_tokens_getFromValue(tokens, string, token_root_sss_separation_techniques_dmvdr_V); settings_validate(token_root_sss_separation_techniques_dmvdr_O);

		token_root_sss_postfiltering_V = json_tokens_getFromObject(tokens, string, token_root_sss_O, "postfiltering"); settings_validate(token_root_sss_postfiltering_V);
		token_root_sss_postfiltering_O = json_tokens_getFromValue(tokens, string, token_root_sss_postfiltering_V); settings_validate(token_root_sss_postfiltering_O);

		token_root_sss_postfiltering_mode_V = json_tokens_getFromObject(tokens, string, token_root_sss_postfiltering_O, "mode"); settings_validate(token_root_sss_postfiltering_mode_V);
		token_root_sss_postfiltering_mode_S = json_tokens_getFromValue(tokens, string, token_root_sss_postfiltering_mode_V); settings_validate(token_root_sss_postfiltering_mode_S);
		token_root_sss_postfiltering_techniques_V = json_tokens_getFromObject(tokens, string, token_root_sss_postfiltering_O, "techniques"); settings_validate(token_root_sss_postfiltering_techniques_V);
		token_root_sss_postfiltering_techniques_O = json_tokens_getFromValue(tokens, string, token_root_sss_postfiltering_techniques_V); settings_validate(token_root_sss_postfiltering_techniques_O);
		token_root_sss_postfiltering_techniques_ms_V = json_tokens_getFromObject(tokens, string, token_root_sss_postfiltering_techniques_O, "ms"); settings_validate(token_root_sss_postfiltering_techniques_ms_V);
		token_root_sss_postfiltering_techniques_ms_O = json_tokens_getFromValue(tokens, string, token_root_sss_postfiltering_techniques_ms_V); settings_validate(token_root_sss_postfiltering_techniques_ms_O);
		token_root_sss_postfiltering_techniques_ms_alphaPmin_V = json_tokens_getFromObject(tokens, string, token_root_sss_postfiltering_techniques_ms_O, "alphaPmin"); settings_validate(token_root_sss_postfiltering_techniques_ms_alphaPmin_V);
		token_root_sss_postfiltering_techniques_ms_alphaPmin_N = json_tokens_getFromValue(tokens, string, token_root_sss_postfiltering_techniques_ms_alphaPmin_V); settings_validate(token_root_sss_postfiltering_techniques_ms_alphaPmin_N);
		token_root_sss_postfiltering_techniques_ms_eta_V = json_tokens_getFromObject(tokens, string, token_root_sss_postfiltering_techniques_ms_O, "eta"); settings_validate(token_root_sss_postfiltering_techniques_ms_eta_V);
		token_root_sss_postfiltering_techniques_ms_eta_N = json_tokens_getFromValue(tokens, string, token_root_sss_postfiltering_techniques_ms_eta_V); settings_validate(token_root_sss_postfiltering_techniques_ms_eta_N);
		token_root_sss_postfiltering_techniques_ms_alphaZ_V = json_tokens_getFromObject(tokens, string, token_root_sss_postfiltering_techniques_ms_O, "alphaZ"); settings_validate(token_root_sss_postfiltering_techniques_ms_alphaZ_V);
		token_root_sss_postfiltering_techniques_ms_alphaZ_N = json_tokens_getFromValue(tokens, string, token_root_sss_postfiltering_techniques_ms_alphaZ_V); settings_validate(token_root_sss_postfiltering_techniques_ms_alphaZ_N);
		token_root_sss_postfiltering_techniques_ms_thetaWin_V = json_tokens_getFromObject(tokens, string, token_root_sss_postfiltering_techniques_ms_O, "thetaWin"); settings_validate(token_root_sss_postfiltering_techniques_ms_thetaWin_V);
		token_root_sss_postfiltering_techniques_ms_thetaWin_N = json_tokens_getFromValue(tokens, string, token_root_sss_postfiltering_techniques_ms_thetaWin_V); settings_validate(token_root_sss_postfiltering_techniques_ms_thetaWin_N);
		token_root_sss_postfiltering_techniques_ms_alphaWin_V = json_tokens_getFromObject(tokens, string, token_root_sss_postfiltering_techniques_ms_O, "alphaWin"); settings_validate(token_root_sss_postfiltering_techniques_ms_alphaWin_V);
		token_root_sss_postfiltering_techniques_ms_alphaWin_N = json_tokens_getFromValue(tokens, string, token_root_sss_postfiltering_techniques_ms_alphaWin_V); settings_validate(token_root_sss_postfiltering_techniques_ms_alphaWin_N);
		token_root_sss_postfiltering_techniques_ms_maxAbsenceProb_V = json_tokens_getFromObject(tokens, string, token_root_sss_postfiltering_techniques_ms_O, "maxAbsenceProb"); settings_validate(token_root_sss_postfiltering_techniques_ms_maxAbsenceProb_V);
		token_root_sss_postfiltering_techniques_ms_maxAbsenceProb_N = json_tokens_getFromValue(tokens, string, token_root_sss_postfiltering_techniques_ms_maxAbsenceProb_V); settings_validate(token_root_sss_postfiltering_techniques_ms_maxAbsenceProb_N);
		token_root_sss_postfiltering_techniques_ms_Gmin_V = json_tokens_getFromObject(tokens, string, token_root_sss_postfiltering_techniques_ms_O, "Gmin"); settings_validate(token_root_sss_postfiltering_techniques_ms_Gmin_V);
		token_root_sss_postfiltering_techniques_ms_Gmin_N = json_tokens_getFromValue(tokens, string, token_root_sss_postfiltering_techniques_ms_Gmin_V); settings_validate(token_root_sss_postfiltering_techniques_ms_Gmin_N);
		token_root_sss_postfiltering_techniques_ms_winSizeLocal_V = json_tokens_getFromObject(tokens, string, token_root_sss_postfiltering_techniques_ms_O, "winSizeLocal"); settings_validate(token_root_sss_postfiltering_techniques_ms_winSizeLocal_V);
		token_root_sss_postfiltering_techniques_ms_winSizeLocal_N = json_tokens_getFromValue(tokens, string, token_root_sss_postfiltering_techniques_ms_winSizeLocal_V); settings_validate(token_root_sss_postfiltering_techniques_ms_winSizeLocal_N);
		token_root_sss_postfiltering_techniques_ms_winSizeGlobal_V = json_tokens_getFromObject(tokens, string, token_root_sss_postfiltering_techniques_ms_O, "winSizeGlobal"); settings_validate(token_root_sss_postfiltering_techniques_ms_winSizeGlobal_V);
		token_root_sss_postfiltering_techniques_ms_winSizeGlobal_N = json_tokens_getFromValue(tokens, string, token_root_sss_postfiltering_techniques_ms_winSizeGlobal_V); settings_validate(token_root_sss_postfiltering_techniques_ms_winSizeGlobal_N);
		token_root_sss_postfiltering_techniques_ms_winSizeFrame_V = json_tokens_getFromObject(tokens, string, token_root_sss_postfiltering_techniques_ms_O, "winSizeFrame"); settings_validate(token_root_sss_postfiltering_techniques_ms_winSizeFrame_V);
		token_root_sss_postfiltering_techniques_ms_winSizeFrame_N = json_tokens_getFromValue(tokens, string, token_root_sss_postfiltering_techniques_ms_winSizeFrame_V); settings_validate(token_root_sss_postfiltering_techniques_ms_winSizeFrame_N);
		token_root_sss_postfiltering_techniques_ss_V = json_tokens_getFromObject(tokens, string, token_root_sss_postfiltering_techniques_O, "ss"); settings_validate(token_root_sss_postfiltering_techniques_ss_V);
		token_root_sss_postfiltering_techniques_ss_O = json_tokens_getFromValue(tokens, string, token_root_sss_postfiltering_techniques_ss_V); settings_validate(token_root_sss_postfiltering_techniques_ss_O);
		token_root_sss_postfiltering_techniques_ss_Gmin_V = json_tokens_getFromObject(tokens, string, token_root_sss_postfiltering_techniques_ss_O, "Gmin"); settings_validate(token_root_sss_postfiltering_techniques_ss_Gmin_V);
		token_root_sss_postfiltering_techniques_ss_Gmin_N = json_tokens_getFromValue(tokens, string, token_root_sss_postfiltering_techniques_ss_Gmin_V); settings_validate(token_root_sss_postfiltering_techniques_ss_Gmin_N);
		token_root_sss_postfiltering_techniques_ss_Gmid_V = json_tokens_getFromObject(tokens, string, token_root_sss_postfiltering_techniques_ss_O, "Gmid"); settings_validate(token_root_sss_postfiltering_techniques_ss_Gmid_V);
		token_root_sss_postfiltering_techniques_ss_Gmid_N = json_tokens_getFromValue(tokens, string, token_root_sss_postfiltering_techniques_ss_Gmid_V); settings_validate(token_root_sss_postfiltering_techniques_ss_Gmid_N);
		token_root_sss_postfiltering_techniques_ss_Gslope_V = json_tokens_getFromObject(tokens, string, token_root_sss_postfiltering_techniques_ss_O, "Gslope"); settings_validate(token_root_sss_postfiltering_techniques_ss_Gslope_V);
		token_root_sss_postfiltering_techniques_ss_Gslope_N = json_tokens_getFromValue(tokens, string, token_root_sss_postfiltering_techniques_ss_Gslope_V); settings_validate(token_root_sss_postfiltering_techniques_ss_Gslope_N);	

		// Access each token

		json_tokens_extractFloat(tokens, string, token_root_general_epsilon_N, &(sets->general.epsilon));
		json_tokens_extractInt(tokens, string, token_root_general_size_hopSize_N, &(sets->general.size.hopSize));
		json_tokens_extractInt(tokens, string, token_root_general_size_frameSize_N, &(sets->general.size.frameSize));
		json_tokens_extractInt(tokens, string, token_root_general_samplerate_mu_N, &(sets->general.samplerate.mu));
		json_tokens_extractFloat(tokens, string, token_root_general_samplerate_sigma2_N, &(sets->general.samplerate.sigma2));
		json_tokens_extractFloat(tokens, string, token_root_general_speedofsound_mu_N, &(sets->general.speedofsound.mu));
		json_tokens_extractFloat(tokens, string, token_root_general_speedofsound_sigma2_N, &(sets->general.speedofsound.sigma2));

		sets->general.mics.N = nMics;

		for (iMic = 0; iMic < nMics; iMic++) {

			json_tokens_extractFloat(tokens, string, token_root_general_mics_e_mus_0_N[iMic], &(sets->general.mics.array[iMic].mu[0]));
			json_tokens_extractFloat(tokens, string, token_root_general_mics_e_mus_1_N[iMic], &(sets->general.mics.array[iMic].mu[1]));
			json_tokens_extractFloat(tokens, string, token_root_general_mics_e_mus_2_N[iMic], &(sets->general.mics.array[iMic].mu[2]));

			json_tokens_extractFloat(tokens, string, token_root_general_mics_e_sigma2s_0_N[iMic], &(sets->general.mics.array[iMic].sigma2[0]));
			json_tokens_extractFloat(tokens, string, token_root_general_mics_e_sigma2s_1_N[iMic], &(sets->general.mics.array[iMic].sigma2[1]));
			json_tokens_extractFloat(tokens, string, token_root_general_mics_e_sigma2s_2_N[iMic], &(sets->general.mics.array[iMic].sigma2[2]));
			json_tokens_extractFloat(tokens, string, token_root_general_mics_e_sigma2s_3_N[iMic], &(sets->general.mics.array[iMic].sigma2[3]));
			json_tokens_extractFloat(tokens, string, token_root_general_mics_e_sigma2s_4_N[iMic], &(sets->general.mics.array[iMic].sigma2[4]));
			json_tokens_extractFloat(tokens, string, token_root_general_mics_e_sigma2s_5_N[iMic], &(sets->general.mics.array[iMic].sigma2[5]));
			json_tokens_extractFloat(tokens, string, token_root_general_mics_e_sigma2s_6_N[iMic], &(sets->general.mics.array[iMic].sigma2[6]));
			json_tokens_extractFloat(tokens, string, token_root_general_mics_e_sigma2s_7_N[iMic], &(sets->general.mics.array[iMic].sigma2[7]));
			json_tokens_extractFloat(tokens, string, token_root_general_mics_e_sigma2s_8_N[iMic], &(sets->general.mics.array[iMic].sigma2[8]));

			json_tokens_extractFloat(tokens, string, token_root_general_mics_e_directions_0_N[iMic], &(sets->general.mics.array[iMic].direction[0]));
			json_tokens_extractFloat(tokens, string, token_root_general_mics_e_directions_1_N[iMic], &(sets->general.mics.array[iMic].direction[1]));
			json_tokens_extractFloat(tokens, string, token_root_general_mics_e_directions_2_N[iMic], &(sets->general.mics.array[iMic].direction[2]));

			json_tokens_extractFloat(tokens, string, token_root_general_mics_e_angles_0_N[iMic], &(sets->general.mics.array[iMic].angle[0]));
			json_tokens_extractFloat(tokens, string, token_root_general_mics_e_angles_1_N[iMic], &(sets->general.mics.array[iMic].angle[1]));

		}

		sets->general.spatialfilters.N = nSpatialFilters;

		for (iSpatialFilter = 0; iSpatialFilter < nSpatialFilters; iSpatialFilter++) {

			json_tokens_extractFloat(tokens, string, token_root_general_spatialfilters_e_directions_0_N[iSpatialFilter], &(sets->general.spatialfilters.array[iSpatialFilter].direction[0]));
			json_tokens_extractFloat(tokens, string, token_root_general_spatialfilters_e_directions_1_N[iSpatialFilter], &(sets->general.spatialfilters.array[iSpatialFilter].direction[1]));
			json_tokens_extractFloat(tokens, string, token_root_general_spatialfilters_e_directions_2_N[iSpatialFilter], &(sets->general.spatialfilters.array[iSpatialFilter].direction[2]));

			json_tokens_extractFloat(tokens, string, token_root_general_spatialfilters_e_angles_0_N[iSpatialFilter], &(sets->general.spatialfilters.array[iSpatialFilter].angle[0]));
			json_tokens_extractFloat(tokens, string, token_root_general_spatialfilters_e_angles_1_N[iSpatialFilter], &(sets->general.spatialfilters.array[iSpatialFilter].angle[1]));

		}

		json_tokens_extractInt(tokens, string, token_root_general_nthetas_N, &(sets->general.nThetas));
		json_tokens_extractFloat(tokens, string, token_root_general_gainmin_N, &(sets->general.gainMin));

		json_tokens_extractInt(tokens, string, token_root_sne_b_N, &(sets->sne.b));
		json_tokens_extractFloat(tokens, string, token_root_sne_alphaS_N, &(sets->sne.alphaS));
		json_tokens_extractInt(tokens, string, token_root_sne_L_N, &(sets->sne.L));
		json_tokens_extractFloat(tokens, string, token_root_sne_delta_N, &(sets->sne.delta));
		json_tokens_extractFloat(tokens, string, token_root_sne_alphaD_N, &(sets->sne.alphaD));

		json_tokens_extractInt(tokens, string, token_root_ssl_nPots_N, &(sets->ssl.nPots));
		json_tokens_extractInt(tokens, string, token_root_ssl_nMatches_N, &(sets->ssl.nMatches));
		json_tokens_extractFloat(tokens, string, token_root_ssl_probMin_N, &(sets->ssl.probMin));
		json_tokens_extractInt(tokens, string, token_root_ssl_nRefinedLevels_N, &(sets->ssl.nRefinedLevels));
		json_tokens_extractInt(tokens, string, token_root_ssl_interpRate_N, &(sets->ssl.interpRate));

		sets->ssl.scans.N = nScans;

		for (iScan = 0; iScan < nScans; iScan++) {

			json_tokens_extractInt(tokens, string, token_root_ssl_scans_e_level_N[iScan], &(sets->ssl.scans.array[iScan].level));
			json_tokens_extractInt(tokens, string, token_root_ssl_scans_e_delta_N[iScan], &(sets->ssl.scans.array[iScan].delta));

		}

		json_tokens_extractString(tokens, string, token_root_sst_mode_S, sets->sst.mode);
		json_tokens_extractString(tokens, string, token_root_sst_add_S, sets->sst.add);

		sets->sst.active.N = nGaussiansActive;

		for (iGaussianActive = 0; iGaussianActive < nGaussiansActive; iGaussianActive++) {

			json_tokens_extractFloat(tokens, string, token_root_sst_energy_active_e_weight_N[iGaussianActive], &(sets->sst.active.array[iGaussianActive].weight));
			json_tokens_extractFloat(tokens, string, token_root_sst_energy_active_e_mu_N[iGaussianActive], &(sets->sst.active.array[iGaussianActive].mu));
			json_tokens_extractFloat(tokens, string, token_root_sst_energy_active_e_sigma2_N[iGaussianActive], &(sets->sst.active.array[iGaussianActive].sigma2));

		}

		sets->sst.inactive.N = nGaussiansInactive;

		for (iGaussianInactive = 0; iGaussianInactive < nGaussiansInactive; iGaussianInactive++) {

			json_tokens_extractFloat(tokens, string, token_root_sst_energy_inactive_e_weight_N[iGaussianInactive], &(sets->sst.inactive.array[iGaussianInactive].weight));
			json_tokens_extractFloat(tokens, string, token_root_sst_energy_inactive_e_mu_N[iGaussianInactive], &(sets->sst.inactive.array[iGaussianInactive].mu));
			json_tokens_extractFloat(tokens, string, token_root_sst_energy_inactive_e_sigma2_N[iGaussianInactive], &(sets->sst.inactive.array[iGaussianInactive].sigma2));

		}		

		json_tokens_extractFloat(tokens, string, token_root_sst_sigmaR2_prob_N, &(sets->sst.sigmaR2.prob));
		json_tokens_extractFloat(tokens, string, token_root_sst_sigmaR2_active_N, &(sets->sst.sigmaR2.active));
		json_tokens_extractFloat(tokens, string, token_root_sst_sigmaR2_target_N, &(sets->sst.sigmaR2.target));

		json_tokens_extractFloat(tokens, string, token_root_sst_P_false_N, &(sets->sst.P.pFalse));
		json_tokens_extractFloat(tokens, string, token_root_sst_P_new_N, &(sets->sst.P.pNew));
		json_tokens_extractFloat(tokens, string, token_root_sst_P_track_N, &(sets->sst.P.pTrack));

		json_tokens_extractFloat(tokens, string, token_root_sst_levels_new_theta_N, &(sets->sst.levels.lNew.theta));
		sets->sst.levels.lNew.N = 0;
		
		json_tokens_extractFloat(tokens, string, token_root_sst_levels_prob_theta_N, &(sets->sst.levels.lProb.theta));
		sets->sst.levels.lProb.N = 1;
		json_tokens_extractInt(tokens, string, token_root_sst_levels_prob_N_N, &(sets->sst.levels.lProb.Ns[0]));
		
		json_tokens_extractFloat(tokens, string, token_root_sst_levels_inactive_theta_N, &(sets->sst.levels.lInactive.theta));
		sets->sst.levels.lInactive.N = nLevels;		
		for (iLevel = 0; iLevel < nLevels; iLevel++) {
			json_tokens_extractInt(tokens, string, token_root_sst_levels_inactive_Ns_e_N[iLevel], &(sets->sst.levels.lInactive.Ns[iLevel]));
		}

		json_tokens_extractFloat(tokens, string, token_root_sst_kalman_sigmaQ_N, &(sets->sst.kalman.sigmaQ));

		json_tokens_extractInt(tokens, string, token_root_sst_particle_nParticles_N, &(sets->sst.particle.nParticles));
		json_tokens_extractFloat(tokens, string, token_root_sst_particle_stationary_alpha_N, &(sets->sst.particle.stationary.alpha));
		json_tokens_extractFloat(tokens, string, token_root_sst_particle_stationary_beta_N, &(sets->sst.particle.stationary.beta));
		json_tokens_extractFloat(tokens, string, token_root_sst_particle_stationary_ratio_N, &(sets->sst.particle.stationary.ratio));
		json_tokens_extractFloat(tokens, string, token_root_sst_particle_velocity_alpha_N, &(sets->sst.particle.velocity.alpha));
		json_tokens_extractFloat(tokens, string, token_root_sst_particle_velocity_beta_N, &(sets->sst.particle.velocity.beta));
		json_tokens_extractFloat(tokens, string, token_root_sst_particle_velocity_ratio_N, &(sets->sst.particle.velocity.ratio));
		json_tokens_extractFloat(tokens, string, token_root_sst_particle_acceleration_alpha_N, &(sets->sst.particle.acceleration.alpha));
		json_tokens_extractFloat(tokens, string, token_root_sst_particle_acceleration_beta_N, &(sets->sst.particle.acceleration.beta));
		json_tokens_extractFloat(tokens, string, token_root_sst_particle_acceleration_ratio_N, &(sets->sst.particle.acceleration.ratio));
		json_tokens_extractFloat(tokens, string, token_root_sst_particle_Nmin_N, &(sets->sst.particle.Nmin));

		json_tokens_extractInt(tokens, string, token_root_sss_offset_N, &(sets->sss.offset));

		json_tokens_extractString(tokens, string, token_root_sss_separation_mode_S, sets->sss.separation.mode);
		json_tokens_extractFloat(tokens, string, token_root_sss_separation_techniques_dgss_mu_N, &(sets->sss.separation.techniques.dgss.mu));
		json_tokens_extractFloat(tokens, string, token_root_sss_separation_techniques_dgss_lambda_N, &(sets->sss.separation.techniques.dgss.lambda));

		json_tokens_extractString(tokens, string, token_root_sss_postfiltering_mode_S, sets->sss.postfiltering.mode);
		json_tokens_extractFloat(tokens, string, token_root_sss_postfiltering_techniques_ms_alphaPmin_N, &(sets->sss.postfiltering.techniques.ms.alphaPmin));
		json_tokens_extractFloat(tokens, string, token_root_sss_postfiltering_techniques_ms_eta_N, &(sets->sss.postfiltering.techniques.ms.eta));
		json_tokens_extractFloat(tokens, string, token_root_sss_postfiltering_techniques_ms_alphaZ_N, &(sets->sss.postfiltering.techniques.ms.alphaZ));
		json_tokens_extractFloat(tokens, string, token_root_sss_postfiltering_techniques_ms_thetaWin_N, &(sets->sss.postfiltering.techniques.ms.thetaWin));
		json_tokens_extractFloat(tokens, string, token_root_sss_postfiltering_techniques_ms_alphaWin_N, &(sets->sss.postfiltering.techniques.ms.alphaWin));
		json_tokens_extractFloat(tokens, string, token_root_sss_postfiltering_techniques_ms_maxAbsenceProb_N, &(sets->sss.postfiltering.techniques.ms.maxAbsenceProb));
		json_tokens_extractFloat(tokens, string, token_root_sss_postfiltering_techniques_ms_Gmin_N, &(sets->sss.postfiltering.techniques.ms.Gmin));
		json_tokens_extractInt(tokens, string, token_root_sss_postfiltering_techniques_ms_winSizeLocal_N, &(sets->sss.postfiltering.techniques.ms.winSizeLocal));
		json_tokens_extractInt(tokens, string, token_root_sss_postfiltering_techniques_ms_winSizeGlobal_N, &(sets->sss.postfiltering.techniques.ms.winSizeGlobal));
		json_tokens_extractInt(tokens, string, token_root_sss_postfiltering_techniques_ms_winSizeFrame_N, &(sets->sss.postfiltering.techniques.ms.winSizeFrame));
		json_tokens_extractFloat(tokens, string, token_root_sss_postfiltering_techniques_ss_Gmin_N, &(sets->sss.postfiltering.techniques.ss.Gmin));
		json_tokens_extractFloat(tokens, string, token_root_sss_postfiltering_techniques_ss_Gmid_N, &(sets->sss.postfiltering.techniques.ss.Gmid));
		json_tokens_extractFloat(tokens, string, token_root_sss_postfiltering_techniques_ss_Gslope_N, &(sets->sss.postfiltering.techniques.ss.Gslope));

		// Free

		free((void *) line);
		free((void *) string);
		json_tokens_destroy(tokens);

	}

	void settings_printf(const settings * sets) {

		unsigned int n;
		unsigned int d;

		printf("general.epsilon = %e\n", sets->general.epsilon);
		printf("general.size.hopSize = %u\n", sets->general.size.hopSize);
		printf("general.size.frameSize = %u\n", sets->general.size.frameSize);
		printf("general.samplerate.mu = %u\n", sets->general.samplerate.mu);
		printf("general.samplerate.sigma2 = %f\n", sets->general.samplerate.sigma2);
		printf("general.speedofsound.mu = %f\n", sets->general.speedofsound.mu);
		printf("general.speedofsound.sigma2 = %f\n", sets->general.speedofsound.sigma2);

		for (n = 0; n < sets->general.mics.N; n++) {

			printf("general.mics[%u].mu = [ ", n);
			for (d = 0; d < 3; d++) {
				printf("%f ", sets->general.mics.array[n].mu[d]);
			}
			printf("]\n");

			printf("general.mics[%u].sigma2 = [ ", n);
			for (d = 0; d < 9; d++) {
				printf("%f ", sets->general.mics.array[n].sigma2[d]);
			}
			printf("]\n");

			printf("general.mics[%u].direction = [ ", n);
			for (d = 0; d < 3; d++) {
				printf("%f ", sets->general.mics.array[n].direction[d]);
			}
			printf("]\n");

			printf("general.mics[%u].angle = [ ", n);
			for (d = 0; d < 2; d++) {
				printf("%f ", sets->general.mics.array[n].angle[d]);
			}
			printf("]\n");

		}

		for (n = 0; n < sets->general.spatialfilters.N; n++) {

			printf("general.spatialfilters[%u].direction = [ ", n);
			for (d = 0; d < 3; d++) {
				printf("%f ", sets->general.spatialfilters.array[n].direction[d]);
			}
			printf("]\n");

			printf("general.spatialfilters[%u].angle = [ ", n);
			for (d = 0; d < 2; d++) {
				printf("%f ", sets->general.spatialfilters.array[n].angle[d]);
			}
			printf("]\n");			

		}

		printf("general.nThetas = %u\n", sets->general.nThetas);
		printf("general.gainMin = %f\n", sets->general.gainMin);

		printf("\n");

		printf("sne.b = %u\n", sets->sne.b);
		printf("sne.alphaS = %f\n", sets->sne.alphaS);
		printf("sne.L = %u\n", sets->sne.L);
		printf("sne.delta = %f\n", sets->sne.delta);
		printf("sne.alphaD = %f\n", sets->sne.alphaD);

		printf("\n");

		printf("ssl.nPots = %u\n", sets->ssl.nPots);
		printf("ssl.nMatches = %u\n", sets->ssl.nMatches);
		printf("ssl.probMin = %f\n", sets->ssl.probMin);
		printf("ssl.nRefinedLevels = %u\n", sets->ssl.nRefinedLevels);
		printf("ssl.interpRate = %u\n", sets->ssl.interpRate);

		for (n = 0; n < sets->ssl.scans.N; n++) {

			printf("ssl.scans[%u].level = %u\n", n, sets->ssl.scans.array[n].level);
			printf("ssl.scans[%u].delta = %d\n", n, sets->ssl.scans.array[n].delta);

		}

		printf("\n");

		printf("sst.mode = %s­\n", sets->sst.mode);
		printf("sst.add = %s\n", sets->sst.add);

		for (n = 0; n < sets->sst.inactive.N; n++) {

			printf("sst.energy.inactive[%u].weight = %f\n", n, sets->sst.inactive.array[n].weight);
			printf("sst.energy.inactive[%u].mu = %f\n", n, sets->sst.inactive.array[n].mu);
			printf("sst.energy.inactive[%u].sigma2 = %f\n", n, sets->sst.inactive.array[n].sigma2);

		}

		for (n = 0; n < sets->sst.active.N; n++) {

			printf("sst.energy.active[%u].weight = %f\n", n, sets->sst.active.array[n].weight);
			printf("sst.energy.active[%u].mu = %f\n", n, sets->sst.active.array[n].mu);
			printf("sst.energy.active[%u].sigma2 = %f\n", n, sets->sst.active.array[n].sigma2);

		}

		printf("sst.sigmaR2.prob = %f\n", sets->sst.sigmaR2.prob);
		printf("sst.sigmaR2.active = %f\n", sets->sst.sigmaR2.active);
		printf("sst.sigmaR2.target = %f\n", sets->sst.sigmaR2.target);

		printf("sst.P.false = %f\n", sets->sst.P.pFalse);
		printf("sst.P.new = %f\n", sets->sst.P.pNew);
		printf("sst.P.track = %f\n", sets->sst.P.pTrack);

		printf("sst.levels.lNew.theta = %f\n", sets->sst.levels.lNew.theta);
		printf("sst.levels.lProb.theta = %f\n", sets->sst.levels.lProb.theta);
		printf("sst.levels.lProb.N = %u\n", sets->sst.levels.lProb.Ns[0]);
		printf("sst.levels.lInactive.theta = %f\n", sets->sst.levels.lInactive.theta);

		for (n = 0; n < sets->sst.levels.lInactive.N; n++) {
			printf("sst.levels.lInactive.Ns[%u] = %u\n", n, sets->sst.levels.lInactive.Ns[n]);
		}

		printf("sst.kalman.sigmaQ = %f\n", sets->sst.kalman.sigmaQ);

		printf("sst.particle.nParticles = %u\n", sets->sst.particle.nParticles);
		printf("sst.particle.stationary.alpha = %f\n", sets->sst.particle.stationary.alpha);
		printf("sst.particle.stationary.beta = %f\n", sets->sst.particle.stationary.beta);
		printf("sst.particle.stationary.ratio = %f\n", sets->sst.particle.stationary.ratio);
		printf("sst.particle.velocity.alpha = %f\n", sets->sst.particle.velocity.alpha);
		printf("sst.particle.velocity.beta = %f\n", sets->sst.particle.velocity.beta);
		printf("sst.particle.velocity.ratio = %f\n", sets->sst.particle.velocity.ratio);
		printf("sst.particle.acceleration.alpha = %f\n", sets->sst.particle.acceleration.alpha);
		printf("sst.particle.acceleration.beta = %f\n", sets->sst.particle.acceleration.beta);
		printf("sst.particle.acceleration.ratio = %f\n", sets->sst.particle.acceleration.ratio);
		printf("sst.particle.Nmin = %f\n", sets->sst.particle.Nmin);

		printf("\n");

		printf("sss.offset = %u\n", sets->sss.offset);
		printf("sss.separation.mode = \"%s\"\n", sets->sss.separation.mode);
		printf("sss.separation.techniques.dgss.mu = %f\n", sets->sss.separation.techniques.dgss.mu);
		printf("sss.separation.techniques.dgss.lambda = %f\n", sets->sss.separation.techniques.dgss.lambda);
		printf("sss.postfiltering.mode = \"%s\"\n", sets->sss.postfiltering.mode);
		printf("sss.postfiltering.techniques.ms.alphaPmin = %f\n", sets->sss.postfiltering.techniques.ms.alphaPmin);
		printf("sss.postfiltering.techniques.ms.eta = %f\n", sets->sss.postfiltering.techniques.ms.eta);
		printf("sss.postfiltering.techniques.ms.alphaZ = %f\n", sets->sss.postfiltering.techniques.ms.alphaZ);
		printf("sss.postfiltering.techniques.ms.thetaWin = %f\n", sets->sss.postfiltering.techniques.ms.thetaWin);
		printf("sss.postfiltering.techniques.ms.alphaWin = %f\n", sets->sss.postfiltering.techniques.ms.alphaWin);
		printf("sss.postfiltering.techniques.ms.maxAbsenceProb = %f\n", sets->sss.postfiltering.techniques.ms.maxAbsenceProb);
		printf("sss.postfiltering.techniques.ms.Gmin = %f\n", sets->sss.postfiltering.techniques.ms.Gmin);
		printf("sss.postfiltering.techniques.ms.winSizeLocal = %u\n", sets->sss.postfiltering.techniques.ms.winSizeLocal);
		printf("sss.postfiltering.techniques.ms.winSizeGlobal = %u\n", sets->sss.postfiltering.techniques.ms.winSizeGlobal);
		printf("sss.postfiltering.techniques.ms.winSizeFrame = %u\n", sets->sss.postfiltering.techniques.ms.winSizeFrame);
		printf("sss.postfiltering.techniques.ss.Gmin = %f\n", sets->sss.postfiltering.techniques.ss.Gmin);
		printf("sss.postfiltering.techniques.ss.Gmid = %f\n", sets->sss.postfiltering.techniques.ss.Gmid);
		printf("sss.postfiltering.techniques.ss.Gslope = %f\n", sets->sss.postfiltering.techniques.ss.Gslope);

	}

	void settings_validate(int token) {

		if (token == -1) {

			printf("Error parsing JSON\n");
			exit(EXIT_FAILURE);

		}		

	}