Vim�UnDo� 7S �~g,�->�G�^�D|���b��m7O�   &   				if(a[j] < prev){            7       7   7   7    g��    _�                             ����                                                                                                                                                                                                                                                                                                                                                             ge�}     �                   5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ge��     �                �             5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             ge��     �      	         	�             5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ge��     �         	      	cin >> k >> n;5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ge��     �         	      	cin >> n >> n;5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ge��     �         
      	�      	   	    5�_�                    
       ����                                                                                                                                                                                                                                                                                                                                                             ge�#     �   	            	for(int i = 0; i < n;5�_�      	              
       ����                                                                                                                                                                                                                                                                                                                                                             ge�&     �   	            	for(int i = 1; i < n;5�_�      
           	          ����                                                                                                                                                                                                                                                                                                                                                             ge�]     �   
            '		if(a[i] < a[i-1])ans+= a[i-1]-a[i]+1;5�_�   	              
          ����                                                                                                                                                                                                                                                                                                                                                             ge�^     �               			�             5�_�   
                        ����                                                                                                                                                                                                                                                                                                                                                             ge�g     �               			�             5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ge�m    �               	�             5�_�                    	        ����                                                                                                                                                                                                                                                                                                                                                             ge��    �   	            	�   	          5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             ge��     �             �             5�_�                       	    ����                                                                                                                                                                                                                                                                                                                                                             ge��    �               #include<iostream>5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             ge��     �               	�             5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ge��     �               		�             5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ge��     �               			�             5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ge�O     �               		�             5�_�                          ����                                                                                                                                                                                                                                                                                                                                                             ge�j     �             5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             ge��     �                		�             5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ge��     �                		for(int j = 0; j < n; j++){5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ge��     �                		int prev = 0;5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ge��     �                			if(1<<j & i)5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ge��     �         $      					�         #    5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ge�     �         (      			�         '    5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ge�     �         *      		�         )    5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ge�#     �         *      					ans += prev-a[j]+1;5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ge�6     �         *      					prev += 1;5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             ge�6     �         *      					prev + 1;5�_�      !                      ����                                                                                                                                                                                                                                                                                                                                                             ge�6     �         *      					prev +1;5�_�       "           !          ����                                                                                                                                                                                                                                                                                                                                                             ge�7     �         *      					prev +;5�_�   !   #           "          ����                                                                                                                                                                                                                                                                                                                                                             ge�:     �          +      		�          *    5�_�   "   $           #            ����                                                                                                                                                                                                                                                                                                                                        '          V       ge�G     �                         	for(int i = 1; i < n; i++){   		if(a[i] < a[i-1]){   			ans+= a[i-1]-a[i]+1;   			a[i] = a[i-1]+1;   		}   	}5�_�   #   %           $          ����                                                                                                                                                                                                                                                                                                                                                   V       ge�I    �      !   $      		�      !   #    5�_�   $   &           %          ����                                                                                                                                                                                                                                                                                                                                                             ge��    �   
      $      	long ans = 0;5�_�   %   '           &          ����                                                                                                                                                                                                                                                                                                                                                             ge��     �         $      		int prev = a[0];5�_�   &   (           '          ����                                                                                                                                                                                                                                                                                                                                                             ge��     �         $      		int prev = 1LL<<60;5�_�   '   )           (          ����                                                                                                                                                                                                                                                                                                                                                             ge��     �         %      				�         $    5�_�   (   *           )          ����                                                                                                                                                                                                                                                                                                                                                             ge��    �         '      				if(a[j] < prev){5�_�   )   +           *          ����                                                                                                                                                                                                                                                                                                                                                             ge�b    �         '      		for(int j = 1; j < n; j++){5�_�   *   ,           +          ����                                                                                                                                                                                                                                                                                                                                                             ge��     �         '      		long prev = 1LL<<60;5�_�   +   -           ,           ����                                                                                                                                                                                                                                                                                                                                                V       ge��     �                				if(prev == 1LL<<60){   					prev = a[j];   				}5�_�   ,   .           -          ����                                                                                                                                                                                                                                                                                                                                                V       ge��     �         $      				else if(a[j] < prev){5�_�   -   /           .          ����                                                                                                                                                                                                                                                                                                                                                V       ge��     �         $      				lse if(a[j] < prev){5�_�   .   0           /          ����                                                                                                                                                                                                                                                                                                                                                V       ge��     �         $      				se if(a[j] < prev){5�_�   /   1           0          ����                                                                                                                                                                                                                                                                                                                                                V       ge��     �         $      				e if(a[j] < prev){5�_�   0   2           1          ����                                                                                                                                                                                                                                                                                                                                                V       ge��    �         $      				 if(a[j] < prev){5�_�   1   3           2          ����                                                                                                                                                                                                                                                                                                                                                             ge��     �         %      			�         $    5�_�   2   4           3          ����                                                                                                                                                                                                                                                                                                                                                             ge��     �                			5�_�   3   6           4          ����                                                                                                                                                                                                                                                                                                                                                             ge��    �          $      			}5�_�   4   7   5       6          ����                                                                                                                                                                                                                                                                                                                                                             ge�Q    �         &      		long prev = a[0];5�_�   6               7          ����                                                                                                                                                                                                                                                                                                                                                             g��    �         &      				if(a[j] < prev){5�_�   4           6   5          ����                                                                                                                                                                                                                                                                                                                                                             ge��     �         &      					prev += ;5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             ge�h     �                5��