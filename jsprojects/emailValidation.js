const isValidEmail = (string) => {
  let regex = /^\w+([.-]?\w+)*@\w+([.-]?\w+)*(\.\w{2,})+$/;
  return regex.test(string);
};

String.prototype.isValidEmail = function () {
  let regex = /^\w+([.-]?\w+)*@\w+([.-]?\w+)*(\.\w{2,})+$/;
  return regex.test(this);
};
