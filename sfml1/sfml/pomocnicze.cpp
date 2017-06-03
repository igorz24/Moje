	// zmiana wielkoœci okna
				case Event::Resized:
					cout << "new width: " << event.size.width << std::endl;
					cout << "new height: " << event.size.height << std::endl;
					break;

					// Program spad³ z 1 planu
				case Event::LostFocus:
					cout << "Lost focus" << endl;
					// myGame.pause();
					break;

					// Program wróci³ na 1 plan
				case Event::GainedFocus:
					cout << "gained focus" << endl;
					// myGame.resume();
					break;

						case Event::KeyReleased:
					cout << "Key released" << endl;

						// Myszka
				case Event::MouseButtonPressed:
					switch (event.key.code) {

					case Mouse::Left:
						
						break;

					case Mouse::Right:
						
						break;
					}

					break;

				case Event::MouseButtonReleased:
					switch (event.key.code) {
					case Mouse::Left:
						
						break;

					case Mouse::Right:
					
						break;
					}

					break;