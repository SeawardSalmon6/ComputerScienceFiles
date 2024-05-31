import { useNavigation } from "@react-navigation/native";

export function useAppNavigation() {
  const navigation = useNavigation();

  const goTo = (to, params) => {
    navigation.navigate(to, params);
  };

  const goBack = () => {
    if (navigation.canGoBack()) {
      navigation.goBack();
    } else {
      goTo("Home");
    }
  };

  const getGoTo = (to) => () => goTo(to);

  return { goTo, getGoTo, goBack, navigation };
}
