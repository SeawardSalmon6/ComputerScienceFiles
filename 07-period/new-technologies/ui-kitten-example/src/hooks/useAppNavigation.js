import { useNavigation } from "@react-navigation/native";

export function useAppNavigation() {
  const navigation = useNavigation();

  const goBack = () => {
    if (navigation.canGoBack()) {
      navigation.goBack();
    }
  };

  const goTo = (route) => {
    navigation.navigate(route);
  };

  const getGoTo = (where) => () => goTo(where);

  return {
    ...navigation,
    goBack,
    goTo,
    getGoTo,
  };
}
