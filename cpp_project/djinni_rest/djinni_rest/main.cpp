//
//  main.cpp
//  djinni_rest
//
//  Created by Christoph Pageler on 25.01.16.
//  Copyright © 2016 Christoph Pageler. All rights reserved.
//

#include <iostream>
#include "post_service_impl.hpp"

int main(int argc, const char * argv[]) {
	
	auto rest_service = djinni_rest::PostsServiceImpl();
	auto posts_index = rest_service.get_posts_index();
	
	std::cout << "Posts Size: " << posts_index.size() << std::endl;
	
    return 0;
}
